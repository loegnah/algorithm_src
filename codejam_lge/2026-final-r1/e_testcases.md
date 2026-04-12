# E - Treasure Hunt Test Cases

## TC1: Example (from problem)
```
3 3
1 3 3
4 2 2
3 2 6
#..
.#.
.##
```
**Expected:** 7
Probe (1,1) cost 2, then worst-case 5 more for total 7.

## TC2: 1x1 clean
```
1 1
5
.
```
**Expected:** 0
Single clean cell = position known.

## TC3: 1x1 dirty
```
1 1
5
#
```
**Expected:** 0
Single dirty cell = treasure is in contaminated area.

## TC4: 1x2 both clean
```
1 2
3 7
..
```
**Expected:** 3
Probe cheaper cell (0,0) cost 3: found or not → determines other cell.

## TC5: 1x2 one clean one dirty (.#)
```
1 2
3 7
.#
```
**Expected:** 3
Need to distinguish clean cell from dirty group. Probe (0,0) cost 3.

## TC6: 1x2 both dirty
```
1 2
3 7
##
```
**Expected:** 0
All dirty = treasure in contaminated area.

## TC7: 1x3 all clean
```
1 3
5 2 8
...
```
**Expected:** 2
Probe (0,1) cost 2: found → done. Not found → Y>1 or Y<1, each leaves 1 clean cell → done.

## TC8: 2x2 all clean uniform cost
```
2 2
1 1
1 1
..
..
```
**Expected:** 3
4 categories need 3 probes in worst case.

## TC9: 3x3 all dirty
```
3 3
1 2 3
4 5 6
7 8 9
###
###
###
```
**Expected:** 0
No clean cells, treasure must be in contaminated area.

## TC10: 2x1 both clean
```
2 1
3
7
.
.
```
**Expected:** 3
Probe cheaper cell (0,0) cost 3.
