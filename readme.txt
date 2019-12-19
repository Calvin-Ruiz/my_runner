Finite runner created with CSFML.
Based on Le-cube available on https://github.com/Calvin-Ruiz/Le-cube

USAGE
  ./my_runner map.lvl

OPTIONS
  -f max_fps	    define max fps		(60 at default)
  -r		    run level			(skip the menu)
  -p		    run in practice mode	(skip the menu)
  -e		    edit map			(skip the menu)
  -n nb_lines	    create new map and edit it	(skip the menu)
  -s width height   resize window on open
  -h		    print the usage and quit

USER INTERACTIONS
  SPACE_KEY	    jump or start
  KEY_P		    toggle practice mode
  SHIFT		    step move of 10 instead of 1
  ESCAPE	    pause
  KEY_LEFT          left move
  KEY_RIGHT         right move
  LEFT_CLIC	    place bloc (editor only)
  RIGHT_CLIC	    remove bloc (editor only)
  MOUSE_ROLL	    change selected bloc (editor only)
		    change bloc type if SHIFT is pressed
  MOUSE_ROLL_BUTTON change bloc types
