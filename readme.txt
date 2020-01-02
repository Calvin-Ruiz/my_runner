Finite runner created with CSFML.
Originally based on Le-cube available on https://github.com/Calvin-Ruiz/Le-cube
Developped by Calvin Ruiz
Textures by Yohan Ruiz

USAGE
  ./my_runner map.lvl

OPTIONS
  -f max_fps	    define max fps		(60 at default)
  -r		    run level			(skip the menu)
  -p		    run in practice mode	(skip the menu, not available yet)
  -e		    edit map			(skip the menu)
  -n nb_lines	    create new map and edit it	(skip the menu)
  -s width height   resize window on open
  -h		    print the usage and quit

USER INTERACTIONS
  SPACE_KEY	    jump or activate sphere
  KEY_P		    toggle practice mode	(not available yet)
  SHIFT		    step move of 10 instead of 1(editor only)
  ESCAPE	    pause
  KEY_LEFT          left move
  KEY_RIGHT         right move
  LEFT_CLIC	    place bloc			(editor only)
		    select bloc 		(editor tools window)
  RIGHT_CLIC	    remove bloc			(editor only)
		    switch page			(editor tools window)
  MOUSE_ROLL	    change selected bloc	(editor only)
		    step move of 4 if SHIFT is pressed
  KEY_P             shoot
