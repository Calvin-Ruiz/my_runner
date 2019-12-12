Finite runner created with CSFML.
Based on Le-cube available on https://github.com/Calvin-Ruiz/Le-cube

USAGE
  ./my_runner map.lvl

OPTIONS
  -f max_fps	define max fps  (60 at default)
  -r		run level  (skip the menu)
  -p		run in practice mode  (skip the menu)
  -e		edit map  (skip the menu)
  -n nb_lines	create new map and edit it  (skip the menu)
  -O		optimize game speed (can cause bug)
  -h		print the usage and quit

USER INTERACTIONS
  SPACE_KEY	jump or start
  KEY_P		toggle practice mode
  SHIFT		step move of 10 instead of 1
  ESCAPE	pause
  LEFT_CLIC	place bloc (editor only)
  RIGHT_CLIC	remove bloc (editor only)
  MOUSE_ROLL	change selected bloc (editor only)
  KEY_LEFT	left move (editor only)
  KEY_RIGHT	right move (editor only)
