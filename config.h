#ifdef _WINDOW_CONFIG

/* default window dimensions (overwritten via -g option): */
enum {
	WIN_WIDTH  = 800,
	WIN_HEIGHT = 600
};

/* colors and font are configured with 'background', 'foreground' and
 * 'font' X resource properties.
 * See X(7) section Resources and xrdb(1) for more information.
 */

#endif
#ifdef _IMAGE_CONFIG

/* levels (in percent) to use when zooming via '-' and '+':
 * (first/last value is used as min/max zoom level)
 */
static const float zoom_levels[] = {
       0.1,    2.0,    5.0,    9.0,
      12.5,   25.0,   37.5,   50.0,
      75.0,  100.0,  125.0,  150.0,
     200.0,  250.0,  300.0,  350.0,
     400.0,  500.0,  600.0,  700.0,
     850.0, 1000.0, 1150.0, 1300.0,
    1500.0, 1700.0, 1900.0, 2100.0,
    2400.0, 2700.0, 3000.0, 4000.0
};

/* default slideshow delay (in sec, overwritten via -S option): */
enum { SLIDESHOW_DELAY = 4 };

/* gamma correction: the user-visible ranges [-GAMMA_RANGE, 0] and
 * (0, GAMMA_RANGE] are mapped to the ranges [0, 1], and (1, GAMMA_MAX].
 * */
static const double GAMMA_MAX   = 10.0;
static const int    GAMMA_RANGE = 32;

/* command i_scroll pans image 1/PAN_FRACTION of screen width/height */
static const int PAN_FRACTION = 4;

/* if false, pixelate images at zoom level != 100%,
 * toggled with 'a' key binding
 */
static const bool ANTI_ALIAS = true;

/* if true, use a checkerboard background for alpha layer,
 * toggled with 'A' key binding
 */
static const bool ALPHA_LAYER = true;

#endif
#ifdef _THUMBS_CONFIG

/* thumbnail sizes in pixels (width == height): */
static const int thumb_sizes[] = { 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352 };

/* thumbnail size at startup, index into thumb_sizes[]: */
static const int THUMB_SIZE = 3;

#endif
#ifdef _MAPPINGS_CONFIG

/* keyboard mappings for image and thumbnail mode: */
static const keymap_t keys[] = {
	/* modifiers    key               function              argument */
	{ 0,            XK_q,             g_quit,               None },
	{ 0,            XK_Return,        g_switch_mode,        None },
	{ 0,            XK_f,             g_toggle_fullscreen,  None },
	{ 0,            XK_t,             g_toggle_bar,         None },
	{ 0,            XK_g,             g_first,              None },
	{ 0,            XK_Home,          g_first,              None },
	{ 0,            XK_G,             g_n_or_last,          None },
	{ 0,            XK_End,           g_n_or_last,          None },
	{ 0,            XK_r,             g_reload_image,       None },
	{ 0,            XK_Delete,        g_remove_image,       None },
	{ ControlMask,  XK_h,             g_scroll_screen,      DIR_LEFT },
	{ ControlMask,  XK_Left,          g_scroll_screen,      DIR_LEFT },
	{ ControlMask,  XK_j,             g_scroll_screen,      DIR_DOWN },
	{ ControlMask,  XK_Down,          g_scroll_screen,      DIR_DOWN },
	{ ControlMask,  XK_k,             g_scroll_screen,      DIR_UP },
	{ ControlMask,  XK_Up,            g_scroll_screen,      DIR_UP },
	{ ControlMask,  XK_l,             g_scroll_screen,      DIR_RIGHT },
	{ ControlMask,  XK_Right,         g_scroll_screen,      DIR_RIGHT },
	{ 0,            XK_plus,          g_zoom,               +1 },
	{ 0,            XK_KP_Add,        g_zoom,               +1 },
	{ 0,            XK_equal,         g_zoom,               +1 },
	{ 0,            XK_minus,         g_zoom,               -1 },
	{ 0,            XK_KP_Subtract,   g_zoom,               -1 },
	{ 0,            XK_m,             g_toggle_image_mark,  None },
	{ ControlMask,  XK_M,             g_mark_range,         None },
	{ ControlMask,  XK_m,             g_reverse_marks,      None },
	{ 0,            XK_M,             g_unmark_all,         None },
	{ 0,            XK_N,             g_navigate_marked,    +1 },
	{ 0,            XK_P,             g_navigate_marked,    -1 },
	{ 0,            XK_braceleft,     g_change_gamma,       -1 },
	{ 0,            XK_braceright,    g_change_gamma,       +1 },
	{ ControlMask,  XK_g,             g_change_gamma,        0 },

	{ 0,            XK_h,             t_move_sel,           DIR_LEFT },
	{ 0,            XK_Left,          t_move_sel,           DIR_LEFT },
	{ 0,            XK_j,             t_move_sel,           DIR_DOWN },
	{ 0,            XK_Down,          t_move_sel,           DIR_DOWN },
	{ 0,            XK_k,             t_move_sel,           DIR_UP },
	{ 0,            XK_Up,            t_move_sel,           DIR_UP },
	{ 0,            XK_l,             t_move_sel,           DIR_RIGHT },
	{ 0,            XK_Right,         t_move_sel,           DIR_RIGHT },
	{ ControlMask,  XK_r,             t_reload_all,         None },

	{ 0,            XK_n,             i_navigate,           +1 },
	{ 0,            XK_n,             i_scroll_to_edge,     DIR_LEFT | DIR_UP },
	{ 0,            XK_Next,          i_navigate,           +10 },
	{ 0,            XK_Next,          i_scroll_to_edge,     DIR_LEFT | DIR_UP },
	{ 0,            XK_p,             i_navigate,           -1 },
	{ 0,            XK_p,             i_scroll_to_edge,     DIR_LEFT | DIR_UP },
	{ 0,            XK_Prior,         i_navigate,           -10 },
	{ 0,            XK_Prior,         i_scroll_to_edge,     DIR_LEFT | DIR_UP },
	{ ControlMask,  XK_6,             i_alternate,          None },
	{ 0,            XK_greater,       i_navigate_frame,     +1 },
	{ 0,            XK_less,          i_navigate_frame,     -1 },
	{ 0,            XK_space,         i_toggle_animation,   None },
	{ 0,            XK_h,             i_scroll,             DIR_LEFT },
	{ 0,            XK_Left,          i_scroll,             DIR_LEFT },
	{ 0,            XK_j,             i_scroll,             DIR_DOWN },
	{ 0,            XK_Down,          i_scroll,             DIR_DOWN },
	{ 0,            XK_k,             i_scroll,             DIR_UP },
	{ 0,            XK_Up,            i_scroll,             DIR_UP },
	{ 0,            XK_l,             i_scroll,             DIR_RIGHT },
	{ 0,            XK_Right,         i_scroll,             DIR_RIGHT },
	{ 0,            XK_asterisk,      i_set_zoom,           100 },
	{ 0,            XK_KP_Multiply,   i_set_zoom,           100 },
	{ 0,            XK_w,             i_fit_to_win,         SCALE_DOWN },
	{ 0,            XK_W,             i_fit_to_win,         SCALE_WIDTH },
	{ 0,            XK_H,             i_fit_to_win,         SCALE_HEIGHT },
	{ 0,            XK_L,             i_rotate,             DEGREE_270 },
	{ 0,            XK_R,             i_rotate,             DEGREE_90 },
	{ 0,            XK_bar,           i_flip,               FLIP_HORIZONTAL },
	{ 0,            XK_underscore,    i_flip,               FLIP_VERTICAL },
	{ 0,            XK_a,             i_toggle_antialias,   None },
	{ 0,            XK_A,             i_toggle_alpha,       None },
	{ 0,            XK_d,             i_slideshow,          None },
};

/* mouse button mappings for image mode: */
static const button_t buttons[] = {
	/* modifiers    button            function              argument */
	{ 0,            1,                i_cursor_navigate,    None },
	{ 0,            2,                i_drag,               DRAG_ABSOLUTE },
	{ 0,            3,                g_switch_mode,        None },
	{ 0,            4,                g_zoom,               +1 },
	{ 0,            5,                g_zoom,               -1 },
};

#endif
