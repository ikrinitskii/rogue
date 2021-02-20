#include <ncurses.h>
#include "array2d.hpp"
#include <vector>

void drawArray(const Array2d &array) noexcept
{
    for (size_t i = 0; i < array.getHeight(); ++i) {
        for (size_t j = 0; j < array.getWidth(); ++j)
            addch(array[i][j]);
        addch('\n');
    }
}

int main()
{
    initscr();
    raw();
    noecho();

    std::vector<Array2d> map = {
    {
            "################",
            " |...#____#...|",
            "##...:____:...##",
            " |...:____:...|",
            "##..##____##..##",
            " |............|",
            "##..##....#########",
            "#....#....#.......#",
            "#....#....#.......|",
            "##..###...##..##..#",
            "#.....#...........|",
            "#.....#...##......#",
            "####.###..#.......#",
            "   |...#..#########",
            "  ##........|",
            "   |........|",
            "  ##====######",
            "   ######"
    },
   {
            "  ############",
            " #   #    #   #",
            " #   #    #   #",
            " #   #    #   #",
            " #  ##    ##  #",
            " #            #",
            " #  ##    ####",
            "#    #    #",
            "#    #    #",
            " #  ###   #",
            "#     #   #",
            "#     #   #",
            " ### ###  #",
            "   #   #  ##",
            "   #        #",
            "   #        #",
                "########"
    },
    };

    bool keep_work = true;
    while (keep_work) {

        move(0, 0);
        drawArray(map[0]);
        refresh();

        switch (getch()) {

            case 'q':
            case 'Q':
                keep_work = false;
                break;

            default:
                break;
        }
    }

    endwin();
    return 0;
}