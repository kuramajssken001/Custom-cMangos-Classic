/**
* ScriptData
* SDName:      npc_custom_box
* SD%Complete: 100
* SDComment:自定义功能
* EndScriptData
**/

//#include "sc_gossip.h"
//#include "GossipDef.h"
//#include "Player.h"
#include "precompiled.h"
#include "Chat.h"

#define SETSKILL_MAXVAL           300          //商业技能最大值
#define SETSKILL_ITEM_VALUE_1     80           //增加技能最大值需要的物品数量1
#define SETSKILL_ITEM_VALUE_2     100          //增加技能最大值需要的物品数量2

/*####################
## npc_tool
######################*/

bool GossipHello_npc_tool(Player* pPlayer, Creature* pCreature)
{
	pPlayer->ADD_GOSSIP_ITEM(4, "|cFF0041FF积分查询|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
	pPlayer->ADD_GOSSIP_ITEM(4, "|cFF0041FF积分兑换上古铸币|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
	pPlayer->ADD_GOSSIP_ITEM(4, "|cFF0041FF我要秒专业|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
	pPlayer->ADD_GOSSIP_ITEM(4, "|cFF0041FF[50铸币]修改角色名称|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
	//pPlayer->ADD_GOSSIP_ITEM(4, "|cFF0041FF[30铸币]开启双天赋包月-未实现|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
	//pPlayer->ADD_GOSSIP_ITEM(4, "|cFF0041FF[30铸币]开启瞬飞包月-未实现|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);		
	pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
	return true;
}

bool GossipSelect_npc_tool(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
	if (!pPlayer)
		return true;

	switch (uiAction)
	{
		case GOSSIP_ACTION_INFO_DEF + 1:
		{
			//pPlayer->GetSession()->SendNotification("你当前帐户积分：%d ", pPlayer->Getjifen());
			pPlayer->GetSession()->SendNotification("|cFFFFFF33你当前帐户积分：|r|cFF33FF00%d|r ", pPlayer->Getjifen());
			pPlayer->PlayerTalkClass->CloseGossip();
			break;
		}

		case GOSSIP_ACTION_INFO_DEF + 2:  //上古铸币兑换
		{
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(4, "|cFF0041FF兑换1个上古铸币|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cFF0041FF兑换10个上古铸币|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 101);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cFF0041FF兑换100个上古铸币|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 102);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cFFCC00CC注意：兑换的时候至少需要一个背包格子。出现损失概不负责。|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 103);
			pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			break;
		}

		case GOSSIP_ACTION_INFO_DEF + 3: //秒升专业
		{
			pPlayer->PlayerTalkClass->ClearMenus();
				
			pPlayer->ADD_GOSSIP_ITEM(4, "[100币]炼金等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 200);
			pPlayer->ADD_GOSSIP_ITEM(4, "[100币]锻造等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 201);
			pPlayer->ADD_GOSSIP_ITEM(4, "[100币]裁缝等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 202);
			pPlayer->ADD_GOSSIP_ITEM(4, "[100币]工程等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 203);
			pPlayer->ADD_GOSSIP_ITEM(4, "[100币]制皮等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 204);
			pPlayer->ADD_GOSSIP_ITEM(4, "[100币]附魔等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 205);
			pPlayer->ADD_GOSSIP_ITEM(4, "[80币]钓鱼等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 206);
			pPlayer->ADD_GOSSIP_ITEM(4, "[80币]烹饪等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 207);
			pPlayer->ADD_GOSSIP_ITEM(4, "[80币]采矿等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 208);
			pPlayer->ADD_GOSSIP_ITEM(4, "[80币]草药等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 209);
			pPlayer->ADD_GOSSIP_ITEM(4, "[80币]剥皮等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 210);
			//pPlayer->ADD_GOSSIP_ITEM(4, "[100币]急救等级加满　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 211);
			pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			break;
		}

		case GOSSIP_ACTION_INFO_DEF + 4: //名字
		{
			if (pPlayer->HasItemCount(32000, 50, true)) // 判断物品是否足够.
			{
				pPlayer->DestroyItemCount(32000, 50, true);  //销毁用户背包里面的物品
				pPlayer->SetAtLoginFlag(AT_LOGIN_RENAME);    //修改名字
				pPlayer->GetSession()->SendNotification("你需要重新登录，然后才能修改角色的名字！");
				pPlayer->PlayerTalkClass->CloseGossip();

			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的物品不足,无法修改角色名称!");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}

			//////////////////////////////////////////////////上古铸币兑换开始///////////////////////////////////////////////////////////////
		case GOSSIP_ACTION_INFO_DEF + 100:
		{
			if (pPlayer->Getjifen() >= 100)
			{
				pPlayer->AddItem(32000, 1);
				pPlayer->Modifyjifen(-(int32)100);
				pPlayer->PlayerTalkClass->CloseGossip();
				pPlayer->GetSession()->SendNotification("|cFFFFFF33你当前帐户积分：|r|cFF33FF00%d|r ", pPlayer->Getjifen());
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法兑换物品!");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}

		case GOSSIP_ACTION_INFO_DEF + 101:
		{
			if (pPlayer->Getjifen() >= 1000)
			{
				pPlayer->AddItem(32000, 10);
				pPlayer->Modifyjifen(-(int32)1000);
				pPlayer->PlayerTalkClass->CloseGossip();
				pPlayer->GetSession()->SendNotification("|cFFFFFF33你当前帐户积分：|r|cFF33FF00%d|r ", pPlayer->Getjifen());
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法兑换物品!");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}

		case GOSSIP_ACTION_INFO_DEF + 102:
		{
			if (pPlayer->Getjifen() >= 10000)
			{
				pPlayer->AddItem(32000, 100);
				pPlayer->Modifyjifen(-(int32)10000);
				pPlayer->PlayerTalkClass->CloseGossip();
				pPlayer->GetSession()->SendNotification("|cFFFFFF33你当前帐户积分：|r|cFF33FF00%d|r ", pPlayer->Getjifen());
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法兑换物品!");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 103:
		{
			pPlayer->PlayerTalkClass->CloseGossip();
			break;
		}
			//////////////////////////////////////////////////上古铸币兑换结束///////////////////////////////////////////////////////////////


			////////////////////////////////////////////////////秒升专业开始//////////////////////////////////////////////////////////////////
		case GOSSIP_ACTION_INFO_DEF + 200:
		case GOSSIP_ACTION_INFO_DEF + 201:
		case GOSSIP_ACTION_INFO_DEF + 202:
		case GOSSIP_ACTION_INFO_DEF + 203:
		case GOSSIP_ACTION_INFO_DEF + 204:
		case GOSSIP_ACTION_INFO_DEF + 205:
		case GOSSIP_ACTION_INFO_DEF + 206:
		case GOSSIP_ACTION_INFO_DEF + 207:
		case GOSSIP_ACTION_INFO_DEF + 208:
		case GOSSIP_ACTION_INFO_DEF + 209:
		case GOSSIP_ACTION_INFO_DEF + 210:
		//case GOSSIP_ACTION_INFO_DEF + 211://专业  
		{
			uint32 Item_Value = 0;   //物品数量
			uint32 Skill_Type = 0;   //技能类型

			switch (uiAction)
			{
				//炼金171
				case GOSSIP_ACTION_INFO_DEF + 200:
				{
					Item_Value = SETSKILL_ITEM_VALUE_2;
					Skill_Type = SKILL_ALCHEMY;
					break;
				}
				//锻造164
				case GOSSIP_ACTION_INFO_DEF + 201:
				{
					Item_Value = SETSKILL_ITEM_VALUE_2;
					Skill_Type = SKILL_BLACKSMITHING;
					break;
				}
				//裁缝197
				case GOSSIP_ACTION_INFO_DEF + 202:
				{
					Item_Value = SETSKILL_ITEM_VALUE_2;
					Skill_Type = SKILL_TAILORING;
					break;					
				}
				//工程学202
				case GOSSIP_ACTION_INFO_DEF + 203:
				{
					Item_Value = SETSKILL_ITEM_VALUE_2;
					Skill_Type = SKILL_ENGINEERING;
					break;
				}
				//制皮165
				case GOSSIP_ACTION_INFO_DEF + 204:
				{
					Item_Value = SETSKILL_ITEM_VALUE_2;
					Skill_Type = SKILL_LEATHERWORKING;
					break;
				}
				//附魔333
				case GOSSIP_ACTION_INFO_DEF + 205:
				{
					Item_Value = SETSKILL_ITEM_VALUE_2;
					Skill_Type = SKILL_ENCHANTING;
					break;
				}

				//钓鱼
				case GOSSIP_ACTION_INFO_DEF + 206:
				{
					Item_Value = SETSKILL_ITEM_VALUE_1; 
					Skill_Type = SKILL_FISHING;
					break;
				}
				//烹饪
				case GOSSIP_ACTION_INFO_DEF + 207:
				{
					Item_Value = SETSKILL_ITEM_VALUE_1;
					Skill_Type = SKILL_COOKING;
					break;
				}
				//采矿
				case GOSSIP_ACTION_INFO_DEF + 208:
				{
					Item_Value = SETSKILL_ITEM_VALUE_1;
					Skill_Type = SKILL_MINING;
					break;
				}
				//草药
				case GOSSIP_ACTION_INFO_DEF + 209:
				{
					Item_Value = SETSKILL_ITEM_VALUE_1; 
					Skill_Type = SKILL_HERBALISM;
					break;
				}
				//剥皮
				case GOSSIP_ACTION_INFO_DEF + 210:
				{
					Item_Value = SETSKILL_ITEM_VALUE_1;
					Skill_Type = SKILL_SKINNING;
					break;
				}
				//急救
				//case GOSSIP_ACTION_INFO_DEF + 211:
				//{
				//	Item_Value = SETSKILL_ITEM_VALUE_1;
				//	Skill_Type = SKILL_FIRST_AID;
				//	break;
				//}
			}

			if (pPlayer->HasSkill(Skill_Type))
			{
				if (pPlayer->HasItemCount(32000, Item_Value, true) && pPlayer->GetBaseSkillValue(Skill_Type) < SETSKILL_MAXVAL)
				{
					pPlayer->DestroyItemCount(32000, Item_Value, true);  //销毁用户背包里面的物品
					pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
					pPlayer->PlayerTalkClass->CloseGossip();
				}
				else
				{
					//pPlayer->GetSession()->SendNotification("你的物品不足，或者你的技能值已到最大值！技能提升失败.　 ");
					pCreature->MonsterWhisper("|cFFFF00FF你的物品不足，或者你的技能值已到最大值！技能提升失败。|r　 ", pPlayer);   //NPC 密语发送消息
					pPlayer->PlayerTalkClass->CloseGossip();
				}
					
			}
			else
			{
				//pPlayer->GetSession()->SendNotification("你没有学习技能，请学习技能后再来!　 ");
				pCreature->MonsterWhisper("|cFFFF00FF你没有学习技能，请学习技能后再来！|r　 ", pPlayer);   //NPC 密语发送消息
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}
		////////////////////////////////////////////////////秒升专业结束//////////////////////////////////////////////////////////////////

	}
	return true;
};

/*####################
## npc_training_dummy     //训练假人
######################*/

#define OUT_OF_COMBAT_TIME 5000

struct npc_training_dummyAI : public ScriptedAI
{
    npc_training_dummyAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    uint32 combat_timer;

    void Reset() override
    {
        combat_timer = 0;
    }

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
    {
        combat_timer = 0;
    }

    void UpdateAI(const uint32 diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        m_creature->ModifyHealth(m_creature->GetMaxHealth());

        combat_timer += diff;
        if (combat_timer > OUT_OF_COMBAT_TIME)
            EnterEvadeMode();
    }
};

CreatureAI* GetAI_npc_training_dummy(Creature* pCreature)
{
    return new npc_training_dummyAI(pCreature);
}

void AddSC_npc_custom_box()
{
	Script* pNewScript;

	pNewScript = new Script;
	pNewScript->Name = "npc_tool";
	pNewScript->pGossipHello = &GossipHello_npc_tool;
	pNewScript->pGossipSelect = &GossipSelect_npc_tool;
	pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_training_dummy";
    pNewScript->GetAI = &GetAI_npc_training_dummy;
    pNewScript->RegisterSelf();

}
