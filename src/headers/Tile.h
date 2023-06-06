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

        enum Visual
        {
            INVALID = 0
            // TODO
        };

        Tile();

        Type _type;
        Visual _visual;
};

#endif // TILE_H