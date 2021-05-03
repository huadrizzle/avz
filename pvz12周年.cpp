//PE真12炮

#include "avz.h"

using namespace AvZ;

inline void DC()
{
    Card({{PUFF_SHROOM, 1, 9}, {SUN_SHROOM, 2, 9}, {SCAREDY_SHROOM, 5, 9}, {FLOWER_POT, 6, 9}});
}

inline void CC()
{
    Shovel({{1, 9}, {2, 9}, {5, 9}, {6, 9}});
}

inline void ICE()
{
    ice_filler.coffee();
    SetPlantActiveTime(ICE_SHROOM, 298);
}

void Script()
{
    SetZombies({PJ_0, LZ_2, CG_3, GL_7, WW_8, BC_12, HT_14, XC_15, KG_17, TT_18, FT_21, TL_22, BY_23, HY_32});
    SelectCards({COFFEE_BEAN, ICE_SHROOM, M_ICE_SHROOM, LILY_PAD, DOOM_SHROOM, TALL_NUT, PUFF_SHROOM, SUN_SHROOM, SCAREDY_SHROOM, FLOWER_POT});

    pao_operator.resetPaoList({{1, 1},
                               {2, 1},
                               {3, 1},
                               {4, 1},
                               {5, 1},
                               {6, 1},
                               {2, 3},
                               {1, 4},
                               {1, 6},
                               {2, 7},
                               {3, 6},
                               {4, 5},
                               {5, 4},
                               {6, 3},
                               {6, 5},
                               {6, 7}});

    ice_filler.start({{2, 5}, {2, 6}, {5, 6}, {5, 7}});

    SetTime(-600, 1);
    AvZ::MaidCheats::move();
    Card({{LILY_PAD, 3, 8}, {TALL_NUT, 3, 8}});

    for (auto wave : {1, 4, 7, 11, 14, 17})
    {
        if (wave == 1 || wave == 11)
        {
            SetTime(-95, wave);
            pao_operator.pao({{2, 9}, {5, 9}});
            Delay(107);
            pao_operator.pao({{1, 7.7}, {5, 7.7}});
            SetTime(601 - 298 + 1);
            ICE();
            SetTime(601 - 180);
            DC();
            Delay(50);
            CC();
        }
        else
        {
            SetTime(235 - 373, wave);
            pao_operator.pao({{1, 8.8}, {5, 8.8}});
            Delay(107);
            pao_operator.pao({{1, 7.7}, {5, 7.7}});
            SetTime(601 - 298 + 1);
            ICE();
            SetTime(601 - 180);
            DC();
            Delay(50);
            CC();
        }
    }

    for (auto wave : {2, 5, 8, 12, 15, 18})
    {
        SetTime(180, wave);
        pao_operator.pao({{2, 7.16}, {5, 7.16}});
        SetTime(780);
        DC();
        Delay(256);
        CC();
        SetTime(1520 - 373 - 200);
        pao_operator.pao({{2, 8.8}, {5, 8.8}});
        Delay(215);
        pao_operator.pao({{1, 7.6}, {5, 7.6}});
        SetTime(1520 - 298 + 11);
        ICE();
    }

    for (auto wave : {3, 6, 9, 13, 16, 19})
    {
        SetTime(180, wave);
        pao_operator.pao({{2, 7.16}, {5, 7.16}});
        SetTime(780);
        DC();
        Delay(50);
        CC();
        SetTime(1400 - 373 - 200);
        pao_operator.pao({{2, 8.8}, {5, 8.8}});
        Delay(220);
        pao_operator.pao({{1, 8.5}, {5, 8.5}});
        if (wave == 9 || wave == 19)
        {
            Delay(215);
            pao_operator.pao({{1, 8.8}, {5, 8.8}});
            Delay(80);
            pao_operator.pao({{2, 9}, {5, 9}});
            SetTime(11);
            AvZ::MaidCheats::dancing();
        }
    }

    //wave10
    SetTime(-55, 10);
    AvZ::MaidCheats::move();
    pao_operator.pao({{2, 9}, {5, 9}});
    Delay(373 - 298 + 100);
    Card({{LILY_PAD, 3, 9}, {DOOM_SHROOM, 3, 9}, {COFFEE_BEAN, 3, 9}});
    SetPlantActiveTime(DOOM_SHROOM, 298);
    Delay(298 + 110 - 373);
    pao_operator.pao({{1, 8.8}, {5, 8.8}});

    //wave20
    SetTime(-137, 20);
    pao_operator.pao(4, 7);
    SetTime(394 - 373);
    pao_operator.pao(2, 6);
    SetTime(226 - 250);
    AvZ::MaidCheats::move();
    ice_filler.stop();
    Delay(250);
    AvZ::MaidCheats::dancing();
    Shovel({{3, 8}, {3, 8}});
    SetTime(-147);
    pao_operator.pao({{2, 9}, {5, 9}});
    Delay(23);
    pao_operator.pao({{2, 9}, {5, 9}});
    Delay(110);
    pao_operator.pao({{1, 8.8}, {5, 8.8}});
    SetTime(814 - 373);
    pao_operator.pao({{2, 9}, {5, 9}});
}