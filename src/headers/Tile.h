#ifndef TILE_H
#define TILE_H

/*
    Current state of a cave tile. Create 2-dimensional array of tiles to store state of entire cave.
*/
class Tile
{
    public:
        enum class Type
        {
            INVALID,
            WALL,
            FLOOR
        };

        /*
            Each entry corresponds to an index in the TileMap's texture sheet.
            Walls are named based on what directions floor tiles are in, starting 
            from North, and going clockwise around the edges and corners until 
            reaching North-West. F = floor, W = wall in that direction.
            Floors are named with a number as a suffix, this is the variation of 
            that floor, this will be selected from randomly, and all floors are
            considered equivalent.
        */
        enum Visual
        {
            INVALID = 0,   // 0,0
            WALL_WFWWWWWW, // 1,0
            WALL_FFWWWWWF, // 2,0
            WALL_WWWWWWWF, // 3,0
            WALL_WWWWWFFF, // 4,0
            WALL_WFFFWWWW, // 5,0
            WALL_WWWFWWWW, // 6,0
            WALL_WWWFFFWW, // 7,0
            WALL_WWWWWFWW, // 0,1
            WALL_WWWFWFFF, // 1,1
            WALL_FFWFWWWF, // 2,1
            WALL_FFWWWFWF, // 3,1
            WALL_WWWFFFWF, // 4,1
            WALL_WFFFWWWF, // 5,1
            WALL_WFFFWFFF, // 6,1
            WALL_WFWWWFFF, // 7,1
            WALL_WFWFFFWW, // 0,2
            WALL_WWWFWWWF, // 1,2
            WALL_WFWFWWWW, // 2,2
            WALL_WWWWWFWF, // 3,2
            WALL_WWWFWFWW, // 4,2
            WALL_WFFFFFWW, // 5,2
            WALL_FFWWWFFF, // 6,2
            WALL_FFWFFFWF, // 7,2
            WALL_WWWFFFFF, // 0,3
            WALL_WFWWWFWW, // 1,3
            WALL_WFWWWWWF, // 2,3
            WALL_WFWWWFWF, // 3,3
            WALL_WWWFWFWF, // 4,3
            WALL_WFWFWFWW, // 5,3
            WALL_WFWFWWWF, // 6,3
            WALL_FFWFWFWF, // 7,3
            WALL_WFFFWFWF, // 0,4
            WALL_WFWFWFFF, // 1,4
            WALL_WFWFFFWF, // 2,4
            WALL_WFWFFFFF, // 3,4
            WALL_FFWFWFFF, // 4,4
            WALL_FFFFWFWF, // 5,4
            WALL_FFFFWFFF, // 6,4
            WALL_FFFFFFWF, // 7,4
            WALL_WFFFFFWF, // 0,5
            WALL_WFFFFFFF, // 1,5
            WALL_FFWFFFFF, // 2,5
            WALL_FFFFFFFF, // 3,5
            WALL_WFWFWFWF, // 4,5
            FLOOR_1,       // 5,5
            FLOOR_2,       // 6,5
            FLOOR_3,       // 7,5
            FLOOR_4,       // 0,6
            FLOOR_5,       // 1,6
            FLOOR_6,       // 2,6
            FLOOR_7,       // 3,6
            FLOOR_8,       // 4,6
            WALL_WWWWWWWW  // 5,6
        };

        Tile();

        Type type;
        Visual visual;
};

#endif // TILE_H