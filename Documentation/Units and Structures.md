# Units and Structures
Outlines all of the units and structures that are currently implemented or planned. Images will be added to this document as development progresses. 

# Player Units

## Worker
Workers gather resources for the player, be it from fallen enemies or allies, or from the moss veins scattered throughout the caves. Workers are also required to create defensive structures, where the worker will mutate into the desired defensive structure.

## Combat Unit
Currently the only military unit the player has. The player will use their combat unit to scout the map and kill enemy units to secure resources, as well as defend workers as the workers gather resources.

# Player Structures

## Defensive Tower
Attacks enemy units at a range. Can take a bit of a beating, but will fall to enough enemies. 4 tiles in size (2x2).

## Wall
The wall has no offensive abilities of its own, it only serves to soak up damage from the enemies and impede their progress. When a worker mutates into a wall, it will stretch out to fill the entire with of the corridor (up to a reasonable limit) creating a barrier that prevents enemies from crossing until the wall is destroyed. The wall, being a living thing, is still able to let allied units pass through, creating a temporary gaps whenever an allied unit needs access. It will appear as a 1-tile thick wall stretching the width of the corridor it sits in. The wall takes damage as a single unit, meaning a wall stretching 5 tiles wide will have as much durability as a wall stretching only 1 tile wide. The corpse of a wall will be worth the same amount of energy regardless of the size of the wall, it will just be spread over more tiles in the case of a wider wall.

# Enemy Units

## Weak Enemy Unit
The most plentiful enemy the player will encounter, appearing as a creeping black mass, this enemy will be a constant nuissance in the caves. At times they will be so great in number that the entire floor of the cave will appear as a writhing black mass.

Characteristics:
- Slow moving.
- Low health.
- Large in number.
- Size: 1 tile.

## Strong Enemy Unit
A larger version of the weak enemy unit, this unit is as slow as its smaller counterpart, except it has way more health and is much less common.

Characteristics:
- Slow moving.
- Very high health.
- Few in number.
- Size: 4 tiles (2x2).

# Enemy Structures
*There are currently no plans to add any enemy structures.*