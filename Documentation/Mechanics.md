# Mechanics
This document outlines the systems in place in the game that tie everything together.

# Energy
Energy serves two purposes, both as a resource required to obtain victory, and also the only method through which more units and structures can be obtained.

Energy can be obtained from the following sources:
- Workers will passively gain small amounts of energy for the player while sitting idle in base.
- The corpses of dead units or structures, both player and enemy, can be broken down into energy by workers.
- Veins of moss can be found growing along the walls of the caves, which can be mined by the workers who will convert it into energy.

## Energy Thresholds
When the player's total collected energy reaches certain thresholds, they will be provided with a choice of what unit or structure they would like to obtain. These thresholds would be a percentage of the total energy required to obtain victory in the level. This is the players only means of obtaining more units or structures.

Examples of choices offered to the player at an energy threshold might be:
- 1 worker or 1 combat unit.
- 1 combat unit or 1 defensive tower.
- 1 wall or 1 defensive tower.

# Enemy Behaviors
- When a player unit comes into aggro range of an enemy unit, the enemy will chase the player units until they leave the aggro range again.
- When an enemy unit kills a player unit, and no nearby player units remain within the enemy's aggro range, the enemy unit will start to consume the energy from their fallen allies, which will quickly reduce the amount of energy that can be recoved from that corpse, healing the enemy at the same time.

# Vision
When a player starts a level, the entire cave will be hidden to the player, with only a small area around the player's starting point being revealed.

Player units have a vision range. Areas of the cave within this vision range will be revealed to the player, and once an area of the cave has been revealed, that area will remain fully visible to the player until the end of the current level.

# Corpses
When units or structures are killed, their corpses will remain. These corpses can be disposed of in two ways, either by the player's workers harvesting them for resources, or by the enemy units consuming them to deny the resources to the player (which will also restore any lost health).