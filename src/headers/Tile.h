#ifndef TILE_H
#define TILE_H

/*
    Current state of a cave tile. Create 2-dimensional array of tiles to store state of entire cave.
*/
class Tile
{
    public:
        enum Type
        {
            INVALID = 0,
            WALL,
            FLOOR
        };

        // Each entry corresponds to an index in the TileMap's texture sheet.
        enum Visual
        {
            INVALID = 0
            // TODO
        };

        Tile();

        Type type;
        Visual visual;
};

#endif // TILE_H