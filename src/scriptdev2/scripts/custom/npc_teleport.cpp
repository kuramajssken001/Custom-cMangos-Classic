/**
* ScriptData
* SDName:      Npc_teleport
* SD%Complete: 100
* SDComment:世界传送
* EndScriptData
**/

//#include "sc_gossip.h"
//#include "GossipDef.h"
//#include "Player.h"
#include "precompiled.h"

bool GossipHello_npc_teleport(Player* pPlayer, Creature* pCreature)
{
	if (pPlayer->getRace() == 1 || pPlayer->getRace() == 3 || pPlayer->getRace() == 4 || pPlayer->getRace() == 7 || pPlayer->getRace() == 11)//判断是否联盟
	{
		pPlayer->ADD_GOSSIP_ITEM(0, "主城-暴风城　  ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
		pPlayer->ADD_GOSSIP_ITEM(0, "主城-铁炉堡　  ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
		pPlayer->ADD_GOSSIP_ITEM(0, "主城-达纳苏斯  ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
	}
	else
	{
		// 部落 
		pPlayer->ADD_GOSSIP_ITEM(0, "主城-奥格瑞玛  ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
		pPlayer->ADD_GOSSIP_ITEM(0, "主城-雷霆崖　  ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
		pPlayer->ADD_GOSSIP_ITEM(0, "主城-幽暗城　  ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
	}
	//中立
	//pPlayer->ADD_GOSSIP_ITEM(0, "中立-棘齿城  ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
	pPlayer->ADD_GOSSIP_ITEM(0, "中立-藏宝海湾  ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
	//pPlayer->ADD_GOSSIP_ITEM(0, "中立-冬泉谷  ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
	pPlayer->ADD_GOSSIP_ITEM(0, "中立-加基森　  ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);


	pPlayer->SEND_GOSSIP_MENU(99990, pCreature->GetGUID());
	return true;

}

bool GossipSelect_npc_teleport(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
	switch (uiAction)
	{
			// 暴风城 统一格式说明：(MapID, X, Y, Z, 0);
		case GOSSIP_ACTION_INFO_DEF + 1:
			pPlayer->CLOSE_GOSSIP_MENU();
			pPlayer->TeleportTo(0, -8831.41, 625.35, 93.92, 0);
			break;
			// 铁炉堡
		case GOSSIP_ACTION_INFO_DEF + 2:
			pPlayer->CLOSE_GOSSIP_MENU();
			pPlayer->TeleportTo(0, -4923.08, -952.88, 501.53, 0);
			break;
			// 达纳苏斯
		case GOSSIP_ACTION_INFO_DEF + 3:
			pPlayer->CLOSE_GOSSIP_MENU();
			pPlayer->TeleportTo(1, 9952.12, 2280.47, 1341.39, 0);
			break;
			// 奥格瑞玛
		case GOSSIP_ACTION_INFO_DEF + 5:
			pPlayer->CLOSE_GOSSIP_MENU();
			pPlayer->TeleportTo(1, 1605.77, -4388.93, 10, 0);
			break;
			// 雷霆崖
		case GOSSIP_ACTION_INFO_DEF + 6:
			pPlayer->CLOSE_GOSSIP_MENU();
			pPlayer->TeleportTo(1, -1277.57, 123.413, 131.265, 0);
			break;
			// 幽暗城
		case GOSSIP_ACTION_INFO_DEF + 7:
			pPlayer->CLOSE_GOSSIP_MENU();
			pPlayer->TeleportTo(0, 1633.3, 240.18, -43.1, 0);
			break;
			// 棘齿城
			//case GOSSIP_ACTION_INFO_DEF + 9:
			//	pPlayer->CLOSE_GOSSIP_MENU();
			//	pPlayer->TeleportTo(1, -977, -3788, 6, 0);
			//	break;
			// 藏宝海湾
		case GOSSIP_ACTION_INFO_DEF + 10:
			pPlayer->CLOSE_GOSSIP_MENU();
			pPlayer->TeleportTo(0, -14302, 518, 9, 0);
			break;
			// 冬泉谷
			//case GOSSIP_ACTION_INFO_DEF + 11:
			//	pPlayer->CLOSE_GOSSIP_MENU();
			//	pPlayer->TeleportTo(1, 6723.473, -4649.303, 720.980, 4.653);
			//	break;
			// 加基森
		case GOSSIP_ACTION_INFO_DEF + 12:
			pPlayer->CLOSE_GOSSIP_MENU();
			pPlayer->TeleportTo(1, -7177.103, -3788.077, 8.370, 3.621);
			break;
			// 返回
			//case GOSSIP_ACTION_INFO_DEF + 99:
			//	OnGossipHello(pPlayer, pCreature);
			//	break;
	}
	return true;
}




void AddSC_teleport()
{
	Script* pNewScript;

	pNewScript = new Script;
	pNewScript->Name = "npc_teleport";
	pNewScript->pGossipHello = &GossipHello_npc_teleport;
	pNewScript->pGossipSelect = &GossipSelect_npc_teleport;
	pNewScript->RegisterSelf();
}
