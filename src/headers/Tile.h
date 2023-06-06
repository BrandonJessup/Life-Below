#ifndef TILE_H
#define TILE_H

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