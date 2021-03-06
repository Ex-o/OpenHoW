/* OpenHoW
 * Copyright (C) 2017-2018 Mark Sowden <markelswo@gmail.com>
 * Copyright (C) 2017 Daniel Collins <solemnwarning@solemnwarning.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <PL/platform_filesystem.h>
#include <PL/platform_image.h>
#include <PL/platform_console.h>

#include <pork/pork.h>

#define LogInfo(...)  plLogMessage(MAX_PORK_LOGS, __VA_ARGS__)
#define LogWarn(...)  plLogMessage(MAX_PORK_LOGS + 1, __VA_ARGS__)
#define Error(...)    plLogMessage(MAX_PORK_LOGS + 2, __VA_ARGS__)

typedef struct CopyPath {
    const char *input, *output;
} CopyPath;

CopyPath pc_music_paths[]={
        {"/MUSIC/Track02.ogg", "/music/"},
        {"/MUSIC/Track03.ogg", "/music/"},
        {"/MUSIC/Track04.ogg", "/music/"},
        {"/MUSIC/Track05.ogg", "/music/"},
        {"/MUSIC/Track06.ogg", "/music/"},
        {"/MUSIC/Track07.ogg", "/music/"},
        {"/MUSIC/Track08.ogg", "/music/"},
        {"/MUSIC/Track09.ogg", "/music/"},
        {"/MUSIC/Track10.ogg", "/music/"},
        {"/MUSIC/Track11.ogg", "/music/"},
        {"/MUSIC/Track12.ogg", "/music/"},
        {"/MUSIC/Track13.ogg", "/music/"},
        {"/MUSIC/Track14.ogg", "/music/"},
        {"/MUSIC/Track15.ogg", "/music/"},
        {"/MUSIC/Track16.ogg", "/music/"},
        {"/MUSIC/Track17.ogg", "/music/"},
        {"/MUSIC/Track18.ogg", "/music/"},
        {"/MUSIC/Track19.ogg", "/music/"},
        {"/MUSIC/Track20.ogg", "/music/"},
        {"/MUSIC/Track21.ogg", "/music/"},
        {"/MUSIC/Track22.ogg", "/music/"},
        {"/MUSIC/Track23.ogg", "/music/"},
        {"/MUSIC/Track24.ogg", "/music/"},
        {"/MUSIC/Track25.ogg", "/music/"},
        {"/MUSIC/Track26.ogg", "/music/"},
        {"/MUSIC/Track27.ogg", "/music/"},
        {"/MUSIC/Track28.ogg", "/music/"},
        {"/MUSIC/Track29.ogg", "/music/"},
        {"/MUSIC/Track30.ogg", "/music/"},
        {"/MUSIC/Track31.ogg", "/music/"},
        {"/MUSIC/Track32.ogg", "/music/"},
};

CopyPath pc_copy_paths[] = {
        /* text */
        {"/FEText/BIG.tab", "/fe/text/"},
        {"/FEText/BigChars.tab", "/fe/text/"},
        {"/FEText/chars3.tab", "/fe/text/"},
        {"/FEText/CHARS2.tab", "/fe/text/"},
        {"/FEText/GameChars.tab", "/fe/text/"},
        {"/FEText/SMALL.tab", "/fe/text/"},
        {"/FEText/BIG.BMP", "/fe/text/"},
        {"/FEText/BigChars.BMP", "/fe/text/"},
        {"/FEText/chars2D.bmp", "/fe/text/"},
        {"/FEText/chars2L.bmp", "/fe/text/"},
        {"/FEText/Chars2.bmp", "/fe/text/"},
        {"/FEText/CHARS3.BMP", "/fe/text/"},
        {"/FEText/GameChars.bmp", "/fe/text/"},
        {"/FEText/SMALL.BMP", "/fe/text/"},

        /* frontend */

        {"/Language/Tims/Pigbkpc1.BMP", "/fe/"},

        /* briefing */

        {"/Language/Tims/Briefing/loadmult.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/Level0.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/Level1.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/Level1n0.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/Level1n1.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/Level1n2.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/Level1n3.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/Level1n4.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/Level1n5.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/Level2.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/Level3.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level4.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/Level5.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level6.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level7.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level8.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level9.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level10.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level11.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level12.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level13.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level14.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level15.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level16.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level17.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level18.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level19.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level20.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level21.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level22.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level23.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level24.bmp", "/fe/briefing/"},
        {"/Language/Tims/Briefing/level25.bmp", "/fe/briefing/"},

        {"/Language/Tims/Title/ANY.bmp", "/fe/title/"},
        {"/Language/Tims/Title/Bruno1.bmp", "/fe/title/"},
        {"/Language/Tims/Title/KEY.bmp", "/fe/title/"},
        {"/Language/Tims/Title/PRESS.bmp", "/fe/title/"},
        {"/Language/Tims/Title/title.bmp", "/fe/title/"},
        {"/Language/Tims/Title/titlemon.bmp", "/fe/title/"},

        //{"/Language/Tims/Briefing/loadbar.bmp", "/fe/"},  // we're not using this
        //{"/Language/Tims/Debrief/deathm1.bmp", "/fe/debrief/"},
        //{"/Language/Tims/Debrief/deathm2.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/Facepc1.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/Facepc2.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/Facepc3.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/Facepc4.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/Facepc5.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/Facepc6.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/Facepc7.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/Facepc8.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/Facepc9.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/facepcw1.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/facepcw2.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/facepcw3.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/facepcw4.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/facepcw5.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/facepcw6.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/facepcw7.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/facepcw8.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/facepcw9.bmp", "/fe/debrief/"},
        //{"/Language/Tims/Debrief/Hgren.BMP", "/fe/debrief/"},
        //{"/Language/Tims/Debrief/Hpara.BMP", "/fe/debrief/"},
        {"/Language/Tims/Debrief/pcCmmndo.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/pcEngine.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/pcGrenad.BMP", "/fe/debrief/"},
        {"/Language/Tims/Debrief/pcHeavy.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/pcLegend.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/pcMedic.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/pcParatr.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/pcPip1.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/pcPip2.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/pcSniper.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/r_i_p.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/unifeng.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/uniffren.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/unifgerm.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/unifjap.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/uniflard.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/unifruss.bmp", "/fe/debrief/"},
        {"/Language/Tims/Debrief/unifusa.bmp", "/fe/debrief/"},

        {"/Language/Tims/Papers/American.bmp", "/fe/papers/"},
        {"/Language/Tims/Papers/British.bmp", "/fe/papers/"},
        {"/Language/Tims/Papers/French.bmp", "/fe/papers/"},
        {"/Language/Tims/Papers/German.bmp", "/fe/papers/"},
        {"/Language/Tims/Papers/Japan.bmp", "/fe/papers/"},
        {"/Language/Tims/Papers/Russian.bmp", "/fe/papers/"},
        {"/Language/Tims/Papers/teamlard.bmp", "/fe/papers/"},

        {"/Language/Streams/FMV 01.bik", "/streams/"},
        {"/Language/Streams/FMV 02.bik", "/streams/"},
        {"/Language/Streams/FMV 03.bik", "/streams/"},
        {"/Language/Streams/FMV 04.bik", "/streams/"},
        {"/Language/Streams/FMV 05.bik", "/streams/"},
        {"/Language/Streams/FMV 06.bik", "/streams/"},
        {"/Language/Streams/FMV 07.bik", "/streams/"},
        {"/Language/Streams/FMV 08.bik", "/streams/"},
        {"/Language/Streams/FMV 09.bik", "/streams/"},
        {"/Language/Streams/InfoLogo.bik", "/streams/"},
        {"/Language/Streams/Sheff.bik", "/streams/"},

        /* misc */
        {"/Language/Tims/Mine.tim", "/maps/"},
        {"/Language/Tims/wat01.TIM", "/maps/"},
        {"/Language/Tims/wat02.tim", "/maps/"},

        /* maps */
        {"/Maps/BAY.PMG", "/maps/bay/"},
        {"/Maps/ICE.PMG", "/maps/ice/"},
        {"/Maps/BOOM.PMG", "/maps/boom/"},
        {"/Maps/BUTE.PMG", "/maps/bute/"},
        {"/Maps/CAMP.PMG", "/maps/camp/"},
        {"/Maps/DEMO.PMG", "/maps/demo/"},
        {"/Maps/DEVI.PMG", "/maps/devi/"},
        {"/Maps/DVAL.PMG", "/maps/dval/"},
        {"/Maps/EASY.PMG", "/maps/easy/"},
        {"/Maps/ESTU.PMG", "/maps/estu/"},
        {"/Maps/FOOT.PMG", "/maps/foot/"},
        {"/Maps/GUNS.PMG", "/maps/guns/"},
        {"/Maps/KEEP.PMG", "/maps/keep/"},
        {"/Maps/LAKE.PMG", "/maps/lake/"},
        {"/Maps/MAZE.PMG", "/maps/maze/"},
        {"/Maps/ROAD.PMG", "/maps/road/"},
        {"/Maps/TWIN.PMG", "/maps/twin/"},
        {"/Maps/ARCHI.PMG", "/maps/archi/"},
        {"/Maps/BHILL.PMG", "/maps/bhill/"},
        {"/Maps/CMASS.PMG", "/maps/cmass/"},
        {"/Maps/DBOWL.PMG", "/maps/dbowl/"},
        {"/Maps/DEMO2.PMG", "/maps/demo2/"},
        {"/Maps/DVAL2.PMG", "/maps/dval2/"},
        {"/Maps/EYRIE.PMG", "/maps/eyrie/"},
        {"/Maps/FINAL.PMG", "/maps/final/"},
        {"/Maps/HELL2.PMG", "/maps/hell2/"},
        {"/Maps/HELL3.PMG", "/maps/hell3/"},
        {"/Maps/MEDIX.PMG", "/maps/medix/"},
        {"/Maps/MLAKE.PMG", "/maps/mlake/"},
        {"/Maps/OASIS.PMG", "/maps/oasis/"},
        {"/Maps/PLAY1.PMG", "/maps/play1/"},
        {"/Maps/PLAY2.PMG", "/maps/play2/"},
        {"/Maps/RIDGE.PMG", "/maps/ridge/"},
        {"/Maps/SNAKE.PMG", "/maps/snake/"},
        {"/Maps/ZULUS.PMG", "/maps/zulus/"},
        {"/Maps/ARTGUN.PMG", "/maps/artgun/"},
        {"/Maps/BRIDGE.PMG", "/maps/bridge/"},
        {"/Maps/DESVAL.PMG", "/maps/desval/"},
        {"/Maps/FJORDS.PMG", "/maps/fjords/"},
        {"/Maps/GENMUD.PMG", "/maps/genmud/"},
        {"/Maps/ISLAND.PMG", "/maps/island/"},
        {"/Maps/LUNAR1.PMG", "/maps/lunar1/"},
        {"/Maps/MASHED.PMG", "/maps/mashed/"},
        {"/Maps/ONEWAY.PMG", "/maps/oneway/"},
        {"/Maps/RUMBLE.PMG", "/maps/rumble/"},
        {"/Maps/SEPIA1.PMG", "/maps/sepia1/"},
        {"/Maps/SNIPER.PMG", "/maps/sniper/"},
        {"/Maps/TRENCH.PMG", "/maps/trench/"},
        {"/Maps/CREEPY2.PMG", "/maps/creepy/"},
        {"/Maps/EMPLACE.PMG", "/maps/emplace/"},
        {"/Maps/GENLAVA.PMG", "/maps/genlava/"},
        {"/Maps/GENSNOW.PMG", "/maps/gensnow/"},
        {"/Maps/ICEFLOW.PMG", "/maps/iceflow/"},
        {"/Maps/LECPROD.PMG", "/maps/lecprod/"},
        {"/Maps/SUPLINE.PMG", "/maps/supline/"},
        {"/Maps/GENBRACK.PMG", "/maps/genbrack/"},
        {"/Maps/GENCHALK.PMG", "/maps/genchalk/"},
        {"/Maps/GENDESRT.PMG", "/maps/gendesrt/"},
        {"/Maps/HILLBASE.PMG", "/maps/hillbase/"},
        {"/Maps/LIBERATE.PMG", "/maps/liberate/"},
#if 0 /* eventually we'll just copy and load from each PTG */
{"/Maps/BAY.PTG", "/maps/bay/"},
        {"/Maps/ICE.PTG", "/maps/ice/"},
        {"/Maps/BOOM.PTG", "/maps/boom/"},
        {"/Maps/BUTE.PTG", "/maps/bute/"},
        {"/Maps/CAMP.PTG", "/maps/camp/"},
        {"/Maps/DEMO.PTG", "/maps/demo/"},
        {"/Maps/DEVI.PTG", "/maps/devi/"},
        {"/Maps/DVAL.PTG", "/maps/dval/"},
        {"/Maps/EASY.PTG", "/maps/easy/"},
        {"/Maps/ESTU.PTG", "/maps/estu/"},
        {"/Maps/FOOT.PTG", "/maps/foot/"},
        {"/Maps/GUNS.PTG", "/maps/guns/"},
        {"/Maps/KEEP.PTG", "/maps/keep/"},
        {"/Maps/LAKE.PTG", "/maps/lake/"},
        {"/Maps/MAZE.PTG", "/maps/maze/"},
        {"/Maps/ROAD.PTG", "/maps/road/"},
        {"/Maps/TWIN.PTG", "/maps/twin/"},
        {"/Maps/ARCHI.PTG", "/maps/archi/"},
        {"/Maps/BHILL.PTG", "/maps/bhill/"},
        {"/Maps/CMASS.PTG", "/maps/cmass/"},
        {"/Maps/DBOWL.PTG", "/maps/dbowl/"},
        {"/Maps/DEMO2.PTG", "/maps/demo2/"},
        {"/Maps/DVAL2.PTG", "/maps/dval2/"},
        {"/Maps/EYRIE.PTG", "/maps/eyrie/"},
        {"/Maps/FINAL.PTG", "/maps/final/"},
        {"/Maps/HELL2.PTG", "/maps/hell2/"},
        {"/Maps/HELL3.PTG", "/maps/hell3/"},
        {"/Maps/MEDIX.PTG", "/maps/medix/"},
        {"/Maps/MLAKE.PTG", "/maps/mlake/"},
        {"/Maps/OASIS.PTG", "/maps/oasis/"},
        {"/Maps/PLAY1.PTG", "/maps/play1/"},
        {"/Maps/PLAY2.PTG", "/maps/play2/"},
        {"/Maps/RIDGE.PTG", "/maps/ridge/"},
        {"/Maps/SNAKE.PTG", "/maps/snake/"},
        {"/Maps/ZULUS.PTG", "/maps/zulus/"},
        {"/Maps/ARTGUN.PTG", "/maps/artgun/"},
        {"/Maps/BRIDGE.PTG", "/maps/bridge/"},
        {"/Maps/DESVAL.PTG", "/maps/desval/"},
        {"/Maps/FJORDS.PTG", "/maps/fjords/"},
        {"/Maps/GENMUD.PTG", "/maps/genmud/"},
        {"/Maps/ISLAND.PTG", "/maps/island/"},
        {"/Maps/LUNAR1.PTG", "/maps/lunar1/"},
        {"/Maps/MASHED.PTG", "/maps/mashed/"},
        {"/Maps/ONEWAY.PTG", "/maps/oneway/"},
        {"/Maps/RUMBLE.PTG", "/maps/rumble/"},
        {"/Maps/SEPIA1.PTG", "/maps/sepia1/"},
        {"/Maps/SNIPER.PTG", "/maps/sniper/"},
        {"/Maps/TRENCH.PTG", "/maps/trench/"},
        {"/Maps/CREEPY2.PTG", "/maps/creepy/"},
        {"/Maps/EMPLACE.PTG", "/maps/emplace/"},
        {"/Maps/GENLAVA.PTG", "/maps/genlava/"},
        {"/Maps/GENSNOW.PTG", "/maps/gensnow/"},
        {"/Maps/ICEFLOW.PTG", "/maps/iceflow/"},
        {"/Maps/LECPROD.PTG", "/maps/lecprod/"},
        {"/Maps/SUPLINE.PTG", "/maps/supline/"},
        {"/Maps/genbrack.ptg", "/maps/genbrack/"},
        {"/Maps/GENCHALK.PTG", "/maps/genchalk/"},
        {"/Maps/GENDESRT.PTG", "/maps/gendesrt/"},
        {"/Maps/HILLBASE.PTG", "/maps/hillbase/"},
        {"/Maps/LIBERATE.PTG", "/maps/liberate/"},
#endif
        {"/Maps/BAY.POG", "/maps/bay/"},
        {"/Maps/ICE.POG", "/maps/ice/"},
        {"/Maps/BOOM.POG", "/maps/boom/"},
        {"/Maps/BUTE.POG", "/maps/bute/"},
        {"/Maps/CAMP.POG", "/maps/camp/"},
        {"/Maps/DEMO.POG", "/maps/demo/"},
        {"/Maps/DEVI.POG", "/maps/devi/"},
        {"/Maps/DVAL.POG", "/maps/dval/"},
        {"/Maps/EASY.POG", "/maps/easy/"},
        {"/Maps/ESTU.POG", "/maps/estu/"},
        {"/Maps/FOOT.POG", "/maps/foot/"},
        {"/Maps/GUNS.POG", "/maps/guns/"},
        {"/Maps/KEEP.POG", "/maps/keep/"},
        {"/Maps/LAKE.POG", "/maps/lake/"},
        {"/Maps/MAZE.POG", "/maps/maze/"},
        {"/Maps/ROAD.POG", "/maps/road/"},
        {"/Maps/TWIN.POG", "/maps/twin/"},
        {"/Maps/ARCHI.POG", "/maps/archi/"},
        {"/Maps/BHILL.POG", "/maps/bhill/"},
        {"/Maps/CMASS.POG", "/maps/cmass/"},
        {"/Maps/DBOWL.POG", "/maps/dbowl/"},
        {"/Maps/DEMO2.POG", "/maps/demo2/"},
        {"/Maps/DVAL2.POG", "/maps/dval2/"},
        {"/Maps/EYRIE.POG", "/maps/eyrie/"},
        {"/Maps/FINAL.POG", "/maps/final/"},
        {"/Maps/HELL2.POG", "/maps/hell2/"},
        {"/Maps/HELL3.POG", "/maps/hell3/"},
        {"/Maps/MEDIX.POG", "/maps/medix/"},
        {"/Maps/MLAKE.POG", "/maps/mlake/"},
        {"/Maps/OASIS.POG", "/maps/oasis/"},
        {"/Maps/PLAY1.POG", "/maps/play1/"},
        {"/Maps/PLAY2.POG", "/maps/play2/"},
        {"/Maps/RIDGE.POG", "/maps/ridge/"},
        {"/Maps/SNAKE.POG", "/maps/snake/"},
        {"/Maps/ZULUS.POG", "/maps/zulus/"},
        {"/Maps/ARTGUN.POG", "/maps/artgun/"},
        {"/Maps/BRIDGE.POG", "/maps/bridge/"},
        {"/Maps/DESVAL.POG", "/maps/desval/"},
        {"/Maps/FJORDS.POG", "/maps/fjords/"},
        {"/Maps/GENMUD.POG", "/maps/genmud/"},
        {"/Maps/ISLAND.POG", "/maps/island/"},
        {"/Maps/LUNAR1.POG", "/maps/lunar1/"},
        {"/Maps/MASHED.POG", "/maps/mashed/"},
        {"/Maps/ONEWAY.POG", "/maps/oneway/"},
        {"/Maps/RUMBLE.POG", "/maps/rumble/"},
        {"/Maps/SEPIA1.POG", "/maps/sepia1/"},
        {"/Maps/SNIPER.POG", "/maps/sniper/"},
        {"/Maps/TRENCH.POG", "/maps/trench/"},
        {"/Maps/CREEPY2.POG", "/maps/creepy/"},
        {"/Maps/EMPLACE.POG", "/maps/emplace/"},
        {"/Maps/GENLAVA.POG", "/maps/genlava/"},
        {"/Maps/GENSNOW.POG", "/maps/gensnow/"},
        {"/Maps/ICEFLOW.POG", "/maps/iceflow/"},
        {"/Maps/LECPROD.POG", "/maps/lecprod/"},
        {"/Maps/SUPLINE.POG", "/maps/supline/"},
        {"/Maps/GENBRACK.POG", "/maps/genbrack/"},
        {"/Maps/GENCHALK.POG", "/maps/genchalk/"},
        {"/Maps/GENDESRT.POG", "/maps/gendesrt/"},
        {"/Maps/HILLBASE.POG", "/maps/hillbase/"},
        {"/Maps/LIBERATE.POG", "/maps/liberate/"},

        /* chars */
        {"/Chars/pig.HIR", "/chars/"},
        {"/Chars/mcap.mad", "/chars/"},

        /* audio:ambience */
        {"/Audio/AMB_1D.wav", "/audio/"},
        {"/Audio/AMB_1N.wav", "/audio/"},
        {"/Audio/AMB_2D.wav", "/audio/"},
        {"/Audio/AMB_2N.wav", "/audio/"},

        /* audio:explosions */
        {"/Audio/E_1.wav", "/audio/"},
        {"/Audio/E_1000P.wav", "/audio/"},

        /* audio:engines */
        {"/Audio/EN_BIP.wav", "/audio/"},
        {"/Audio/EN_TANK.wav", "/audio/"},

        /* audio:footsteps */
        {"/Audio/FT_GRASS.wav", "/audio/"},
        {"/Audio/FT_ICE.wav", "/audio/"},
        {"/Audio/FT_LAVA.wav", "/audio/"},
        {"/Audio/FT_METAL.wav", "/audio/"},
        {"/Audio/FT_MUD.wav", "/audio/"},
        {"/Audio/FT_QUAG.wav", "/audio/"},
        {"/Audio/FT_ROCK.wav", "/audio/"},
        {"/Audio/FT_SAND.wav", "/audio/"},
        {"/Audio/FT_SNOW.wav", "/audio/"},
        {"/Audio/FT_STONE.wav", "/audio/"},
        {"/Audio/FT_SWIM.wav", "/audio/"},
        {"/Audio/FT_WATER.wav", "/audio/"},
        {"/Audio/FT_WOOD.wav", "/audio/"},
};

CopyPath pc_package_paths[] = {
        {"/Chars/british2.mad",         "/chars/pigs/"},    /* actually contains all the pig models */
        {"/Chars/FACES.MTD",            "/chars/faces/"},   /* contains all the face textures       */

        /* hats */
        {"/Chars/BRITHATS.MAD",         "/chars/hats/"},
        {"/Chars/FHATS.MAD",            "/chars/hats/"},

        /* teams */
        {"/Chars/british.mtd",          "/chars/british/"},
        {"/Chars/AMERICAN.MTD",         "/chars/american/"},
        {"/Chars/FRENCH.MTD",           "/chars/french/"},
        {"/Chars/GERMAN.MTD",           "/chars/german/"},
        {"/Chars/JAPANESE.MTD",         "/chars/japanese/"},
        {"/Chars/RUSSIAN.MTD",          "/chars/russian/"},
        {"/Chars/TEAMLARD.MTD",         "/chars/teamlard/"},

        /* sky */
        {"/Chars/SKYDOME.MAD",          "/sky/"},
        //{"/Chars/SKYDOME.MTD", "/chars/sky/"},    /* unused ?? */
        {"/Chars/TOY.MAD",              "/skys/toy/"},
        {"/Chars/SPACE.MAD",            "/skys/space/"},
        {"/Chars/SUNSET.MAD",           "/skys/sunset/"},
        {"/Chars/SUNRISE.MAD",          "/skys/sunrise/"},
        {"/Chars/SUNNY.MAD",            "/skys/sunny/"},
        {"/Chars/OMINOUS.MAD",          "/skys/ominous/"},
        {"/Chars/DESERT.MAD",           "/skys/desert/"},
        {"/Chars/COLDSKY.MAD",          "/skys/coldsky/"},
        {"/Chars/NIGHT1.MAD",           "/skys/night1/"},

        /* weapons */
        {"/Chars/WEAPONS.MAD",          "/chars/weapons/"},
        {"/Chars/WEAPONS.MTD",          "/chars/weapons/"},

        /* frontend */
        {"/FEBmps/FEBMP.MAD",           "/fe/bitmaps/"},
        {"/Language/Tims/FEFXTIMS.MTD", "/fe/fx/"},
        {"/Language/Tims/EXPLTIMS.MAD", "/fe/expl/"},
        {"/Language/Tims/FACETIMS.MAD", "/fe/dash/"},
        {"/Language/Tims/FLAGTIMS.MAD", "/fe/dash/"},
        {"/Language/Tims/dashtims.mad", "/fe/dash/"},
        {"/Language/Tims/MAPICONS.MTD", "/fe/map/"},
        {"/Language/Tims/MENUTIMS.MAD", "/fe/dash/menu/"},
        {"/Language/Tims/TBOXTIMS.MAD", "/fe/dash/"},

#if 1
        {"/Maps/BAY.PTG",        "/maps/bay/tiles/"},
        {"/Maps/ICE.PTG",        "/maps/ice/tiles/"},
        {"/Maps/BOOM.PTG",       "/maps/boom/tiles/"},
        {"/Maps/BUTE.PTG",       "/maps/bute/tiles/"},
        {"/Maps/CAMP.PTG",       "/maps/camp/tiles/"},
        {"/Maps/DEMO.PTG",       "/maps/demo/tiles/"},
        {"/Maps/DEVI.PTG",       "/maps/devi/tiles/"},
        {"/Maps/DVAL.PTG",       "/maps/dval/tiles/"},
        {"/Maps/EASY.PTG",       "/maps/easy/tiles/"},
        {"/Maps/ESTU.PTG",       "/maps/estu/tiles/"},
        {"/Maps/FOOT.PTG",       "/maps/foot/tiles/"},
        {"/Maps/GUNS.PTG",       "/maps/guns/tiles/"},
        {"/Maps/KEEP.PTG",       "/maps/keep/tiles/"},
        {"/Maps/LAKE.PTG",       "/maps/lake/tiles/"},
        {"/Maps/MAZE.PTG",       "/maps/maze/tiles/"},
        {"/Maps/ROAD.PTG",       "/maps/road/tiles/"},
        {"/Maps/TWIN.PTG",       "/maps/twin/tiles/"},
        {"/Maps/ARCHI.PTG",      "/maps/archi/tiles/"},
        {"/Maps/BHILL.PTG",      "/maps/bhill/tiles/"},
        {"/Maps/CMASS.PTG",      "/maps/cmass/tiles/"},
        {"/Maps/DBOWL.PTG",      "/maps/dbowl/tiles/"},
        {"/Maps/DEMO2.PTG",      "/maps/demo2/tiles/"},
        {"/Maps/DVAL2.PTG",      "/maps/dval2/tiles/"},
        {"/Maps/EYRIE.PTG",      "/maps/eyrie/tiles/"},
        {"/Maps/FINAL.PTG",      "/maps/final/tiles/"},
        {"/Maps/HELL2.PTG",      "/maps/hell2/tiles/"},
        {"/Maps/HELL3.PTG",      "/maps/hell3/tiles/"},
        {"/Maps/MEDIX.PTG",      "/maps/medix/tiles/"},
        {"/Maps/MLAKE.PTG",      "/maps/mlake/tiles/"},
        {"/Maps/OASIS.PTG",      "/maps/oasis/tiles/"},
        {"/Maps/PLAY1.PTG",      "/maps/play1/tiles/"},
        {"/Maps/PLAY2.PTG",      "/maps/play2/tiles/"},
        {"/Maps/RIDGE.PTG",      "/maps/ridge/tiles/"},
        {"/Maps/SNAKE.PTG",      "/maps/snake/tiles/"},
        {"/Maps/ZULUS.PTG",      "/maps/zulus/tiles/"},
        {"/Maps/ARTGUN.PTG",     "/maps/artgun/tiles/"},
        {"/Maps/BRIDGE.PTG",     "/maps/bridge/tiles/"},
        {"/Maps/DESVAL.PTG",     "/maps/desval/tiles/"},
        {"/Maps/FJORDS.PTG",     "/maps/fjords/tiles/"},
        {"/Maps/GENMUD.PTG",     "/maps/genmud/tiles/"},
        {"/Maps/ISLAND.PTG",     "/maps/island/tiles/"},
        {"/Maps/LUNAR1.PTG",     "/maps/lunar1/tiles/"},
        {"/Maps/MASHED.PTG",     "/maps/mashed/tiles/"},
        {"/Maps/ONEWAY.PTG",     "/maps/oneway/tiles/"},
        {"/Maps/RUMBLE.PTG",     "/maps/rumble/tiles/"},
        {"/Maps/SEPIA1.PTG",     "/maps/sepia1/tiles/"},
        {"/Maps/SNIPER.PTG",     "/maps/sniper/tiles/"},
        {"/Maps/TRENCH.PTG",     "/maps/trench/tiles/"},
        {"/Maps/CREEPY2.PTG",    "/maps/creepy/tiles/"},
        {"/Maps/EMPLACE.PTG",    "/maps/emplace/tiles/"},
        {"/Maps/GENLAVA.PTG",    "/maps/genlava/tiles/"},
        {"/Maps/GENSNOW.PTG",    "/maps/gensnow/tiles/"},
        {"/Maps/ICEFLOW.PTG",    "/maps/iceflow/tiles/"},
        {"/Maps/LECPROD.PTG",    "/maps/lecprod/tiles/"},
        {"/Maps/SUPLINE.PTG",    "/maps/supline/tiles/"},
        {"/Maps/genbrack.ptg",   "/maps/genbrack/tiles/"},
        {"/Maps/GENCHALK.PTG",   "/maps/genchalk/tiles/"},
        {"/Maps/GENDESRT.PTG",   "/maps/gendesrt/tiles/"},
        {"/Maps/HILLBASE.PTG",   "/maps/hillbase/tiles/"},
        {"/Maps/LIBERATE.PTG",   "/maps/liberate/tiles/"},

        {"/Skys/COLD/COLD1.PTG", "/skys/cold/"},
#endif
};

/* Extraction process for initial setup */

void ExtractPTGPackage(const char *input_path, const char *output_path) {
    if(input_path == NULL || input_path[0] == '\0') {
        LogInfo("encountered invalid path for PTG, aborting!\n");
        return;
    }

    char ptg_name[PL_SYSTEM_MAX_PATH] = {'\0'};
    plStripExtension(ptg_name, plGetFileName(input_path));
    pl_strtolower(ptg_name);

    if(!plCreatePath(output_path)) {
        LogInfo("failed to create path %s, aborting!\n", output_path);
        return;
    }

    FILE *file = fopen(input_path, "rb");
    if(file == NULL) {
        LogInfo("failed to load %s, aborting!\n", input_path);
        return;
    }

    FILE *out = NULL;

    uint32_t num_textures;
    if(fread(&num_textures, sizeof(uint32_t), 1, file) != 1) {
        LogInfo("invalid PTG file, failed to get number of textures!\n");
        goto ABORT_PTG;
    }

    size_t tim_size = (plGetFileSize(input_path) - sizeof(num_textures)) / num_textures;
    for(unsigned int i = 0; i < num_textures; ++i) {
        uint8_t tim[tim_size];
        if(fread(tim, tim_size, 1, file) != 1) {
            LogInfo("failed to read tim, aborting!\n");
            goto ABORT_PTG;
        }

        char out_path[PL_SYSTEM_MAX_PATH] = {'\0'};
        sprintf(out_path, "%s/%d.tim", output_path, i);
        out = fopen(out_path, "wb");
        if(out == NULL) {
            LogInfo("failed to open %s for writing, aborting!\n", out_path);
            goto ABORT_PTG;
        }

        //print(" %s\n", out_path);
        if(fwrite(tim, tim_size, 1, out) != 1) {
            LogInfo("failed to write %s, aborting!\n", out_path);
            goto ABORT_PTG;
        }

        pork_fclose(out);
    }

    ABORT_PTG:
    pork_fclose(out);
    pork_fclose(file);
}

void ExtractMADPackage(const char *input_path, const char *output_path) {
    if(input_path == NULL || input_path[0] == '\0') { // technically, this should never, ever, ever, ever happen...
        LogInfo("encountered invalid path for MAD, aborting!\n");
        return;
    }

    char package_name[PL_SYSTEM_MAX_PATH] = {'\0'};
    plStripExtension(package_name, plGetFileName(input_path));
    pl_strtolower(package_name);

    if(!plCreatePath(output_path)) {
        LogInfo("failed to create input_path %s, aborting!\n", output_path);
        return;
    }

    FILE *file = fopen(input_path, "rb");
    if(file == NULL) {
        LogInfo("failed to load %s, aborting!\n", input_path);
        return;
    }

    char package_extension[4] = {'\0'};
    snprintf(package_extension, sizeof(package_extension), "%s", plGetFileExtension(input_path));
    pl_strtolower(package_extension);

    FILE *out_index = NULL;
    // check if it's necessary for us to produce an index file
    // since models expect each texture to have a particular
    // position within the MTD package - yay...
    if(strcmp(package_extension, "mtd") == 0) {
        char index_path[PL_SYSTEM_MAX_PATH] = {'\0'};
        sprintf(index_path, "%s/%s.index", output_path, package_name);
        out_index = fopen(index_path, "w");
        if (out_index == NULL) {
            printf("failed to open %s for writing!\n", index_path);
        }
    }

    typedef struct __attribute__((packed)) MADIndex {
        char file[16];

        uint32_t offset;
        uint32_t length;
    } MADIndex;

    uint8_t *data = NULL;
    FILE *out = NULL;
    unsigned int lowest_offset = UINT32_MAX;
    unsigned int cur_index = 0;
    long position;
    do {
        MADIndex index; cur_index++;
        if(fread(&index, sizeof(MADIndex), 1, file) != 1) {
            LogInfo("invalid index size for %s, aborting!\n", package_name);
            goto ABORT_MAD;
        }

        position = ftell(file);
        if(lowest_offset > index.offset) {
            lowest_offset = index.offset;
        }

        // this is where the fun begins...

        // how uses mixed case file-names, to make things
        // easier for linux/macos support we'll just output_path
        // everything as lowercase
        pl_strtolower(index.file);

        char file_path[PL_SYSTEM_MAX_PATH] = {'\0'};
        sprintf(file_path, "%s/%s", output_path, index.file);

        // then check if we need to amend our index file
        if(out_index != NULL) {
            // remove the extension, since we're going to support
            // multiple formats for texture loading, and it's
            // unnecessary to read it in later when we're determining
            // what texture to load :)
            char index_file_path[PL_SYSTEM_MAX_PATH] = {'\0'};
            plStripExtension(index_file_path, index.file);
            fprintf(out_index, "%s\n", index_file_path);
        }

        CHECK_AGAIN:
        // check if we're throwing out any duplicates when copying
        // everything over. technically this shouldn't occur but
        // is primarily being left here for now just for debugging
        // purposes - eventually once we're settled with both the
        // PC and PSX content, we can probably remove it
        if(plFileExists(file_path)) {
            size_t size = plGetFileSize(file_path);
            if(size == index.length) {
                //LogInfo("duplicate file found for %s at %s, skipping!\n", index.file, file_path);
                continue;
            }

            // this part should never happen, but we'll check for it anyway, call me paranoid!
            LogInfo("duplicate file found for %s at %s with differing size (%d vs %zu), renaming!\n",
                  index.file, file_path, index.length, size);
            strcat(file_path, "_");
            goto CHECK_AGAIN;
        }

        data = pork_alloc(index.length, sizeof(uint8_t), false);

        // go and grab the data so we can export!
        fseek(file, index.offset, SEEK_SET);
        if(fread(data, sizeof(uint8_t), index.length, file) != index.length) {
            LogInfo("failed to read %s in %s, aborting!\n", index.file, package_name);
            goto ABORT_MAD;
        }

        out = fopen(file_path, "wb");
        if(out == NULL) {
            LogInfo("failed to open %s for writing, aborting!\n", file_path);
            goto ABORT_MAD;
        }

        //print(" %s\n", file_path);
        if(fwrite(data, sizeof(uint8_t), index.length, out) != index.length) {
            LogInfo("failed to write %s!\n", file_path);
            goto ABORT_MAD;
        }

        pork_fclose(out);
        pork_free(data);

        // return us to where we were in the file
        fseek(file, position, SEEK_SET);
    } while(position < lowest_offset);

    ABORT_MAD:
    pork_free(data);

    pork_fclose(out_index);
    pork_fclose(out);
    pork_fclose(file);
}

void ConvertImageToPNG(const char *path) {
    LogInfo("converting %s...\n", path);

    // figure out if the file already exists before
    // we even start trying to convert this thing
    char out_path[PL_SYSTEM_MAX_PATH] = {'\0'};
    plStripExtension(out_path, path);
    strcat(out_path, ".png");
    if(plFileExists(out_path)) {
        LogInfo("tim already converted, deleting original\n");
        plDeleteFile(path);
        return;
    }

    PLImage image;
    if(!plLoadImage(path, &image)) {
        LogInfo("failed to load \"%s\", %s, aborting!\n", path, plGetError());
        return;
    }

    const char *ext = plGetFileExtension(path);
    if(ext != NULL && ext[0] != '\0' && strcmp(ext, "tim") == 0) {
        // ensure that it's a format we're able to convert from
        if (image.format != PL_IMAGEFORMAT_RGB5A1) {
            LogInfo("unexpected pixel format in \"%s\", aborting!\n", path);
            goto ABORT;
        }

        if (!plConvertPixelFormat(&image, PL_IMAGEFORMAT_RGBA8)) {
            LogInfo("failed to convert \"%s\", %s, aborting!\n", path, plGetError());
            goto ABORT;
        }
    }

    plReplaceImageColour(&image, PLColour(255, 0, 255, 255), PLColour(0, 0, 0, 0));

#if 0
    if(!plFlipImageVertical(&image)) {
        LogInfo("failed to flip \"%s\", %s, aborting!\n", path, plGetError());
        goto ABORT;
    }
#endif

    if(!plWriteImage(&image, out_path)) {
        LogInfo("failed to write png \"%s\", %s, aborting!\n", out_path, plGetError());
        goto ABORT;
    }

    plFreeImage(&image);
    plDeleteFile(path);

    ABORT:
    plFreeImage(&image);
}

/****************************************************/
/* Texture Merger                                   */

typedef struct TMergeTarget {
    const char *path;
    unsigned int x, y;
} TMergeTarget;

typedef struct TMerge {
    const char *output;
    unsigned int num_textures;
    unsigned int width, height;
    TMergeTarget targets[10];
} TMerge;

TMerge texture_targets[]={
        {
            "fe/dash/ang.png", 5, 152, 121, {{
                "fe/dash/ang1.tim", 0, 0
            }, {
                "fe/dash/ang2.tim", 64, 22
            }, {
                "fe/dash/ang3.tim", 0, 64
            }, {
                "fe/dash/ang4.tim", 64, 64
            }, {
                "fe/dash/ang5.tim", 128, 31
            }}
        },

        {
            "fe/dash/clock.png", 4, 128, 96, {{
                "fe/dash/clock01.tim", 0, 0
            }, {
                "fe/dash/clock02.tim", 64, 0
            }, {
                "fe/dash/clock03.tim", 0, 28
            }, {
                "fe/dash/clock04.tim", 64, 28
            }}
        },

        {
            "fe/dash/timer.png", 10, 256, 32, {{
                "fe/dash/timer0.tim", 0, 0
            }, {
                "fe/dash/timer1.tim", 24, 0
            }, {
                "fe/dash/timer2.tim", 48, 0
            }, {
                "fe/dash/timer3.tim", 72, 0
            }, {
                "fe/dash/timer4.tim", 96, 0
            }, {
                "fe/dash/timer5.tim", 120, 0
            }, {
                "fe/dash/timer6.tim", 144, 0
            }, {
                "fe/dash/timer7.tim", 168, 0
            }, {
                "fe/dash/timer8.tim", 192, 0
            }, {
                "fe/dash/timer9.tim", 216, 0
            }}
        },

        {
            "fe/dash/pause.png", 8, 64, 64, {{
                "fe/dash/pause1.tim", 0, 0
            }, {
                "fe/dash/pause2.tim", 16, 0
            }, {
                "fe/dash/pause3.tim", 32, 0
            }, {
                "fe/dash/pause4.tim", 0, 16
            }, {
                "fe/dash/pause5.tim", 32, 16
            }, {
                "fe/dash/pause6.tim", 0, 32
            }, {
                "fe/dash/pause7.tim", 16, 32
            }, {
                "fe/dash/pause8.tim", 32, 32
            }}
        }
};

void MergeTextureTargets(void) {
    unsigned int num_texture_targets = plArrayElements(texture_targets);
    LogInfo("merging %d texture targets...\n", num_texture_targets);
    for(unsigned int i = 0; i < num_texture_targets; ++i) {
        TMerge *merge = &texture_targets[i];

        LogInfo("generating %s\n", merge->output);

        PLImage output;
        memset(&output, 0, sizeof(PLImage));
        output.width            = merge->width;
        output.height           = merge->height;
        output.format           = PL_IMAGEFORMAT_RGBA8;
        output.colour_format    = PL_COLOURFORMAT_RGBA;
        output.levels           = 1;
        output.size             = plGetImageSize(output.format, output.width, output.height);
        output.data             = pork_alloc(output.levels, sizeof(uint8_t*), true);
        output.data[0]          = pork_alloc(output.size, sizeof(uint8_t), true);

        for(unsigned int j = 0; j < merge->num_textures; ++j) {
            PLImage image;
            const char *path = pork_find(merge->targets[j].path);
            if(!plLoadImage(path, &image)) {
                LogWarn("failed to find image, \"%s\", for merge!\n", merge->targets[j].path);
                continue;
            }

            plConvertPixelFormat(&image, PL_IMAGEFORMAT_RGBA8);

            LogInfo("writing %s into %s\n", merge->targets[j].path, merge->output);

            uint8_t *pos = output.data[0] + ((merge->targets[j].y * output.width) + merge->targets[j].x) * 4;
            uint8_t *src = image.data[0];
            for(unsigned int y = 0; y < image.height; ++y) {
                memcpy(pos, src, (image.width * 4));
                src += image.width * 4;
                pos += output.width * 4;
            }

            plFreeImage(&image);
            plDeleteFile(path);
        }

        LogInfo("writing %s\n", merge->output);
        plWriteImage(&output, pork_find(merge->output));
        plFreeImage(&output);
    }
}

/*************************************************/

enum {
    VERSION_UNKNOWN,

    VERSION_ENG_PSX,        /* English PSX version */
    VERSION_ENG_PC,         /* English PC version */
    VERSION_ENG_PC_DIGITAL, /* English PC/Digital version */
};

unsigned int CheckGameVersion(const char *path) {
    char fcheck[PL_SYSTEM_MAX_PATH];
    snprintf(fcheck, sizeof(fcheck), "%s/system.cnf", path);
    if(plFileExists(fcheck)) {
        LogInfo("detected system.cnf, assuming PSX version\n");
        return VERSION_ENG_PSX;
    }

    snprintf(fcheck, sizeof(fcheck), "%s/Data/foxscale.d3d", path);
    if(plFileExists(fcheck)) {
        LogInfo("detected Data/foxscale.d3d, assuming PC version\n");
        snprintf(fcheck, sizeof(fcheck), "%s/MUSIC/Track02.ogg", path);
        if(plFileExists(fcheck)) {
            LogInfo("detected MUSIC/Track02.ogg, assuming GOG version\n");
            return VERSION_ENG_PC_DIGITAL;
        } else {
            return VERSION_ENG_PC;
        }
    }

    return VERSION_UNKNOWN;
}

void ProcessPackagePaths(const char *in, const char *out, const CopyPath *paths, unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        char output_path[PL_SYSTEM_MAX_PATH];
        snprintf(output_path, sizeof(output_path), "%s%s", out, paths[i].output);
        if (!plCreatePath(output_path)) {
            LogWarn("%s\n", plGetError());
            continue;
        }

        char input_path[PL_SYSTEM_MAX_PATH];
        snprintf(input_path, sizeof(input_path), "%s%s", in, paths[i].input);
        LogInfo("copying %s to %s\n", input_path, output_path);
        const char *ext = plGetFileExtension(input_path);
        if(pl_strncasecmp(ext, "PTG", 3) == 0) {
            ExtractPTGPackage(input_path, output_path);
        } else {
            ExtractMADPackage(input_path, output_path);
        }
    }
}

void ProcessCopyPaths(const char *in, const char *out, const CopyPath *paths, unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        char output_path[PL_SYSTEM_MAX_PATH];
        snprintf(output_path, sizeof(output_path), "%s%s", out, paths[i].output);
        if (!plCreatePath(output_path)) {
            LogWarn("%s\n", plGetError());
            continue;
        }

        strncat(output_path, plGetFileName(paths[i].input), sizeof(output_path) - strlen(output_path) - 1);
        pl_strtolower(output_path);

        char input_path[PL_SYSTEM_MAX_PATH];
        snprintf(input_path, sizeof(input_path), "%s%s", in, paths[i].input);
        LogInfo("copying %s to %s\n", input_path, output_path);
        plCopyFile(input_path, output_path);
    }
}

int main(int argc, char **argv) {
    if(argc < 1) {
        printf("invalid number of arguments ...\n"
               "  extractor <game_path> ~<out_path>\n");
        return EXIT_SUCCESS;
    }

    char app_dir[PL_SYSTEM_MAX_PATH];
    plGetApplicationDataDirectory(PORK_APP_NAME, app_dir, PL_SYSTEM_MAX_PATH);

    if(!plCreatePath(app_dir)) {
        LogWarn("Unable to create %s: %s\nSettings will not be saved.", app_dir, plGetError());
    }

    char log_path[PL_SYSTEM_MAX_PATH];
    snprintf(log_path, PL_SYSTEM_MAX_PATH, "%s/extraction", app_dir);
    plSetupLogOutput(log_path);

    /* initialize our interface with the engine */

    EngineLauncherInterface interface;
    InitNULLEngineInterface(&interface);

    interface.mode = PORK_MODE_LIMITED;

    InitPork(argc, argv, interface);

    /* set our logs up */

    plSetupLogLevel(MAX_PORK_LOGS, "info", PLColour(0, 255, 0, 255), true);
    plSetupLogLevel(MAX_PORK_LOGS + 1, "warning", PLColour(255, 255, 0, 255), true);
    plSetupLogLevel(MAX_PORK_LOGS + 2, "error", PLColour(255, 0, 0, 255), true);

    /* now deal with any arguments */

    char input_path[PL_SYSTEM_MAX_PATH] = {'\0'};
    for(int i = 1; i < argc; ++i) {
        if(argv[i][0] != '-') {
            strncpy(input_path, argv[i], sizeof(input_path));
            break;
        }
    }

    if(input_path[0] == '\0') {
        Error("invalid game path, aborting!\n");
        return EXIT_FAILURE;
    }

    LogInfo("\n"
            "output path: %s\n"
            "input path:  %s\n",
            GetBasePath(), input_path);

    /* ensure it's a valid version - original CD version requires
     * us to extract audio from the CD while GOG and Steam versions
     * provide OGG audio.
     *
     * PSX is a totally different story, with it's own fun adventure. */
    LogInfo("checking game version...\n");
    unsigned int version = CheckGameVersion(input_path);
    switch(version) {
        default:
        case VERSION_UNKNOWN: {
            Error("unknown game version, aborting!\n");
            return EXIT_FAILURE;
        }

        case VERSION_ENG_PSX: {
            /* todo, psx still needs a lot of thought here...
             * I don't know if we even want to bother? */
            pork_assert(0, "TODO");
            return EXIT_FAILURE;
        }

        case VERSION_ENG_PC: {
            ProcessPackagePaths(input_path, GetBasePath(), pc_package_paths, plArrayElements(pc_package_paths));
            ProcessCopyPaths(input_path, GetBasePath(), pc_copy_paths, plArrayElements(pc_copy_paths));
            // todo: rip music from CD
        } break;

        case VERSION_ENG_PC_DIGITAL: {
            ProcessPackagePaths(input_path, GetBasePath(), pc_package_paths, plArrayElements(pc_package_paths));
            ProcessCopyPaths(input_path, GetBasePath(), pc_copy_paths, plArrayElements(pc_copy_paths));
            ProcessCopyPaths(input_path, GetBasePath(), pc_music_paths, plArrayElements(pc_music_paths));
        } break;
    }

    MergeTextureTargets();

    /* convert the remaining TIM textures to PNG */
    plScanDirectory(GetBasePath(), "tim", ConvertImageToPNG, true);

    LogInfo("complete\n");
    return EXIT_SUCCESS;
}