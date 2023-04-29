# Life Below
Microbial organisms have run out of life-sustaining energy on the planet's surface, and now must search downwards if they hope to survive. Your host organism has run out of energy trying to dig deep, and you must gather whatever energy-providing resources you can from the cave system you have broken into, so that you can continue your journey downward, in search of a better life below.

# To Do
- Fade out dev messages after a delay.
- Add placeholder UI.
- Add additional documentation for:
    - Environment:
        - Cave Layout.
        - Player Starting Area.
        - Enemy Distribution.
        - Enemy Spawning.
        - Enemy Behaviors.
- Create map editor for artist to play around with.
- Import visual assets for prototype.
    - ~~Weak enemy.~~
    - Weak enemy (dead).
    - Strong enemy.
    - Strong enemy (dead).
    - Worker unit.
    - Worker unit (dead).
    - Worker unit (carrying resource).
    - Combat unit.
    - Combat unit (dead).
    - Wall structure.
    - Wall structure (dead).
    - Defensive tower structure.
    - Floor tile.
    - Wall tile.
    - Wall tile with moss.
    - Dead player structure.

# Known issues
- Fonts apply smooth scaling when at scales other than 1, which makes them look blurry.
    - To fix this, glyphs will need to be loaded manually, rather than by using the `sf::Text` class.