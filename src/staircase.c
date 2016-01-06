#include <stdio.h>
#include <stdlib.h>
#include "m_pd.h"

static t_class *staircase_class;

/*** header definition ***/

typedef struct _stairs
{
  t_float   x_step_size,
            x_prev_level,
            x_cur_level;

  t_int     *x_up_hist,
            *x_down_hist,
						x_up_hist_id,
						x_down_hist_id,
            x_rev_nb,
            x_is_finished,
            x_direction,
            x_cur_trial_nb,
            x_stair_id;

  t_atom    x_info[5];

  struct _stairs *p_next;
} t_stairs;

// définition of a stair list type
typedef t_stairs *lstairs;

// object properties
typedef struct _staircase
{
  t_object  x_obj;

  t_float   x_init_step,
            x_eff_rev,
            x_init_level,
            x_reduced_factor;

  t_int     x_up_nb,
            x_down_nb,
            x_stair_max_rev,
            x_stair_max_trials,
            x_answer,
            *x_finished,
            x_cur_stair_id,
            x_cur_stair_hist_id;

  int       x_stair_nb;

  lstairs   x_stairs;

  t_outlet  *f_trial_level,
			      *l_res,
            *b_finished;
} t_staircase;


// Add a stair
static lstairs AddStair ( 
    lstairs stairs, 
    t_int up_size, 
    t_int down_size,
    t_float step_size, 
    t_float init_level, 
    t_int stair_id);
// Select a stair that is not finished
static lstairs SelStair (lstairs stairs, int stair_id);
// Generate a pseudo random ID according to the number of stairs
static int RandStair (t_staircase *x);
// Check if the object is finished
static int IsFinished (t_staircase *x);
// Check if the current stair is finished
//static int StairIsFinished (t_staircase *x, int stair_id);
// Compute the sum of an array
static int PdIntVectorSum (t_int *array, t_int length); 
// reset an array with 0 in it
static void PdIntResetVector (t_int *array, t_int length);
// delete the stair list
static lstairs DeleteStair (lstairs list);
// DEBUG display the list
static void InfoStairs(lstairs list);


static lstairs AddStair (
    lstairs stairs, 
    t_int up_size, 
    t_int down_size,
    t_float step_size, 
    t_float init_level,
    t_int stair_id)
{
  t_stairs *new_stair       = malloc (sizeof (t_stairs));
  new_stair->x_step_size    = step_size;
  new_stair->x_up_hist      = malloc (up_size * sizeof (t_int));
  new_stair->x_down_hist    = malloc (down_size * sizeof (t_int));
  new_stair->x_cur_level    = init_level;
  new_stair->x_stair_id     = stair_id;
  new_stair->x_is_finished  = 0;
  new_stair->x_rev_nb       = 0;
  new_stair->x_cur_trial_nb = 0;
	new_stair->x_up_hist_id		= 0;
	new_stair->x_down_hist_id = 0;
  new_stair->p_next         = stairs;

  return new_stair;
}

static lstairs DeleteStair (lstairs list)
{
    t_stairs *tmp = list;
    t_stairs *tmp_next;
  
    // While we don't reach the end of the list
    while(tmp != NULL)
    {
        // we store the next element to go to the next stair
        tmp_next = tmp->p_next;
        // we delete the current stair and free the space
        free (tmp);
        // we go to the next stair
        tmp = tmp_next;
    }
    // The stair list is empty, we can return NULL
    return NULL;
}

static void InfoStairs(lstairs list)
{
    t_stairs *tmp = list;
	
    // While we don't reach the end of the list
    while(tmp != NULL)
    {
        // We display the current stair information
        post ("stair_id: %d, level: %f, trial nb: %d, rev nb: %d, step size: %f, finished: %d, ", 
            tmp->x_stair_id,
            tmp->x_cur_level,
            tmp->x_cur_trial_nb,
            tmp->x_rev_nb,
            tmp->x_step_size,
            tmp->x_is_finished);
        
		// We go to the next stair
        tmp = tmp->p_next;
    }
}

static lstairs SelStair (lstairs stairs, int stair_id)
{
  t_stairs *tmp_stairs = stairs;

  while (tmp_stairs != NULL)
  {
    if (tmp_stairs->x_stair_id == stair_id)
    {
      if (tmp_stairs->x_is_finished == 1)
        return NULL;
      else
        return tmp_stairs;
    }
    else
      tmp_stairs = tmp_stairs->p_next;
  }

  return NULL;
}

static int RandStair (t_staircase *x)
{
  int rand_value = rand() % x->x_stair_nb;

  return rand_value;
}

static int IsFinished (t_staircase *x)
{
  int sum;
  sum = PdIntVectorSum (x->x_finished, x->x_stair_nb);

  if (sum == x->x_stair_nb)
    return 1;
  else
    return 0;
}

static int PdIntVectorSum (t_int *array, t_int length) 
{
  int i,
      sum = 0;

  for (i = 0; i < length; i++)
  {
    sum = sum + array[i];
  }

  return sum;
}
static void PdIntResetVector (t_int *array, t_int length)
{
  int i;

  for (i = 0; i < length; i++)
  {
    array[i] = 0;
  }
}



/*** Classic PD functions ***/

// outputs are managed directly in the method space
static void staircase_next_float (t_staircase *x, t_float answer)
{
  // casting of answer that is sent as a float
  int tmp_ans = (int) answer;
  float is_reversal = -1;
  int stair_id = RandStair (x);


  // we load the current staircase
  t_stairs *tmp = x->x_stairs,
           *tmp2 = x->x_stairs;
  t_stairs *cur_stair,
           *cur_stair2 = NULL;
  cur_stair = SelStair (tmp, x->x_cur_stair_id);


  // if the stair is finished, we go to the finished label
  if (IsFinished (x))
    goto finished;

  // we store we value of the previous level
  cur_stair->x_prev_level = cur_stair->x_cur_level;
  


  /** processing according to the answer **/
  switch (tmp_ans)
  {
    // incorrect answer
    case 0:
		
			if (cur_stair->x_cur_trial_nb == 0)
				cur_stair->x_direction = 1;
				
			if (cur_stair->x_direction == 0)
			{
				cur_stair->x_direction = 1;
				cur_stair->x_rev_nb += 1;
        is_reversal = 1;
			}
      else
      {
        // it is not a reversal
        is_reversal = 0;
      }
			
			// setup the new level
			cur_stair->x_cur_level = cur_stair->x_cur_level + cur_stair->x_step_size;
			// increment the trial number
      cur_stair->x_cur_trial_nb += 1;
      break;

    // correct answer
    case 1:
			if (cur_stair->x_cur_trial_nb == 0)
				cur_stair->x_direction = 0;
				
			if (cur_stair->x_direction == 1)
			{
				cur_stair->x_direction = 0;
				cur_stair->x_rev_nb += 1;
        is_reversal = 1;
			}
      else
      {
        // it is not a reversal
        is_reversal = 0;
      }
			
			// setup the new level
			cur_stair->x_cur_level = cur_stair->x_cur_level - cur_stair->x_step_size;
			// increment the trial number
      cur_stair->x_cur_trial_nb += 1;
      break;

    // default case
    default:
      error ("the answer is different from 0 or 1");
      break;
  }

  // we set the information in the list
  SETFLOAT(&cur_stair->x_info[0], x->x_cur_stair_id);
  SETFLOAT(&cur_stair->x_info[1], cur_stair->x_cur_trial_nb);
  SETFLOAT(&cur_stair->x_info[2], cur_stair->x_prev_level);
  SETFLOAT(&cur_stair->x_info[3], answer);
  SETFLOAT(&cur_stair->x_info[4], is_reversal);
  outlet_list (x->l_res, 0, 5, cur_stair->x_info);
  
  /*
  // if we reach a certain number of reversals we reduce the step size
  if (cur_stair->x_rev_nb == 3)
    cur_stair->x_step_size = cur_stair->x_step_size / 2;
	*/

  // if trials or the reversals reached the maximum then the stair is over
  if (cur_stair->x_cur_trial_nb == x->x_stair_max_trials || 
      cur_stair->x_rev_nb == x->x_stair_max_rev)
  {
    // we indicate that the current stair is finished
    cur_stair->x_is_finished = 1;
    // we indicate to the global structure that this stair is finished as well
    x->x_finished[x->x_cur_stair_id] = 1;
  }

  // check if the stair is completely over
  if (IsFinished (x))
  {
    goto finished;
  }
  else
  {
    // choose a stair that is unifinished
    while (cur_stair2 == NULL)
    {
      stair_id = RandStair (x);
      cur_stair2 = SelStair (tmp2, stair_id);
    }

    // output the level and  store the stair ID
    outlet_float (x->f_trial_level, cur_stair2->x_cur_level);
    x->x_cur_stair_id = stair_id;
  }

finished:
  if (IsFinished (x))
    outlet_bang (x->b_finished);
}

static void staircase_start (t_staircase *x) 
{
  // creation of the point that will receive the current stair
  t_stairs *tmp = x->x_stairs;
  t_stairs *cur_stair = NULL;
  int stair_id;

  // check if the stair is completely over
  if (IsFinished (x))
    outlet_bang (x->b_finished);
  else
  {
    // choose a stair that is unifinished
    while (cur_stair == NULL)
    {
      stair_id = RandStair (x);
      cur_stair = SelStair (tmp, stair_id);
    }

    // output the level and store the stair ID
    outlet_float (x->f_trial_level, cur_stair->x_cur_level);
    x->x_cur_stair_id = stair_id;
  }
}

static void staircase_reset (t_staircase *x) 
{
  int i;

  // we delete the existing stair
  x->x_stairs = DeleteStair (x->x_stairs);

  // we recreate a new bunch of stairs based on the arguments given to the object.
  for (i = 0; i < x->x_stair_nb; i++)
  {
    x->x_stairs = AddStair (
        x->x_stairs, 
        x->x_up_nb,
        x->x_down_nb,
        x->x_init_step, 
        x->x_init_level, 
        i);

    // we set the finished parameter at 0
    x->x_finished[i] = 0;
  }

}

static void staircase_info (t_staircase *x)
{
  InfoStairs (x->x_stairs);
}

// object constructor (when the object is instanciated)
static void *staircase_new (t_symbol *s, int argc, t_atom *argv)
{
  int i;

  t_staircase *x = (t_staircase *) pd_new(staircase_class);

  // if no argument, we set some starting values
  if (argc < 1)
  {
    x->x_up_nb            = 1;
    x->x_down_nb          = 1;
    x->x_stair_nb         = 2;
    x->x_stair_max_rev    = 6;
    x->x_stair_max_trials = 100;
    x->x_init_level       = 0;
    x->x_init_step        = 1;
  }
  else
  {
    // we get information given in arguments
    x->x_up_nb              = atom_getfloatarg (0, argc, argv);
    x->x_down_nb            = atom_getfloatarg (1, argc, argv);
    x->x_stair_nb           = atom_getfloatarg (2, argc, argv);
    x->x_stair_max_rev      = atom_getfloatarg (3, argc, argv);
    x->x_stair_max_trials   = atom_getfloatarg (4, argc, argv);
    x->x_init_step          = atom_getfloatarg (5, argc, argv);
    x->x_init_level         = atom_getfloatarg (6, argc, argv);
  }
//    post ("stair_nb_1: %f", atom_getfloatarg (2, argc, argv));

  // initialisation of the "finished" array 
  x->x_finished  = malloc (x->x_stair_nb * sizeof (t_int));
  
  // initialisation of the historic id
  x->x_cur_stair_hist_id = 0;

  // creation of the stair cases list
  lstairs stairs = NULL;
  x->x_stairs = stairs;

  // Adding of the stairs and init the finished array
  for (i = 0; i < x->x_stair_nb; i++)
  {
    x->x_stairs = AddStair (
        x->x_stairs, 
        x->x_up_nb,
        x->x_down_nb,
        x->x_init_step, 
        x->x_init_level, 
        i);

    x->x_finished[i] = 0;
  }

  // inlet declarations
  //floatinlet_new (&x->x_obj, &x->x_cur_stair_id); 
  inlet_new ((t_object *) x, (t_pd *) x, &s_bang, gensym("start"));
  inlet_new ((t_object *) x, (t_pd *) x, &s_bang, gensym("reset"));
  inlet_new ((t_object *) x, (t_pd *) x, &s_bang, gensym("info"));

  // outlet declarations
  /*
  x->f_stair_id     = outlet_new (&x->x_obj, &s_float);
  x->f_answer       = outlet_new (&x->x_obj, &s_float);
  x->f_stair_level  = outlet_new (&x->x_obj, &s_float);
  */
  x->l_res			= outlet_new (&x->x_obj, &s_list);
  x->f_trial_level  = outlet_new (&x->x_obj, &s_float);
  x->b_finished     = outlet_new (&x->x_obj, &s_bang);

  return (void *)x;
}

// object setup
void staircase_setup (void)
{
  // creation of the object (symbol creation) and calling of the constructor for
  // its initialisation
  staircase_class = class_new(gensym("staircase"),
      (t_newmethod)staircase_new,
      0, sizeof (t_staircase),
      CLASS_DEFAULT, A_GIMME, 0);

  // here we add the method needed for the object
  class_addmethod (staircase_class, (t_method) staircase_start, gensym("start"), 0);
  class_addfloat (staircase_class, staircase_next_float);
  class_addmethod (staircase_class, (t_method) staircase_reset, gensym("reset"), 0);
  class_addmethod (staircase_class, (t_method) staircase_info, gensym("info"), 0);
}
