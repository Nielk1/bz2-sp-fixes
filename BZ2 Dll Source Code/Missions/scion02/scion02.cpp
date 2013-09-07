#include "..\Shared\SPMission.h"

class scion02 : public SPMission 
{
public:
	scion02(void)
	{
		AllowRandomTracks(false);
		b_count = &b_last - &b_first - 1;
		b_array = &b_first + 1;

		f_count = &f_last - &f_first - 1;
		f_array = &f_first + 1;

		h_count = &h_last - &h_first - 1;
		h_array = &h_first + 1;

		i_count = &i_last - &i_first - 1;
		i_array = &i_first + 1;
	}

	void Setup(void);
	void AddObject(Handle h);
	void HandleScout(void);
	void ArtilleryObjective(void);
	void Execute(void);

	// bools
	bool
		b_first,
		been_detected,
		jammer_exists,
		b_last;

	// floats
	float
		f_first,

		f_last;

	// handles
	Handle
		h_first,
		player,
		talk1,
		enemybase,
		recycler,
		scout,
		oldscout,
		scav1,
		scav2,
		turret1,
		turret2,
		sent1,
		sent2,
		enemytank1,
		enemyscout1,
		enemytank2,
		enemyscout2,
		base_unit_1,
		base_unit_2,
		base_unit_3,
		base_unit_4,
		constructor,
		objective,
		objective2,
		artillery,
		artillery2,
		jammer,
		power1,
		power2,
		art_objective1,
		art_objective2,
		last_objective,
		h_last;


	// integers
	int
		i_first,
		mission_state,
		scout_state,
		scout_counter,
		comp_team,
		increment,
		i_last;
};
DLLBase * BuildMission(void)
{
	return new scion02();
}

void scion02::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools

	been_detected = false;
	jammer_exists = false;
	art_objective1 = false;
	art_objective2 = false;
	last_objective=false;
//  floats

//  handles
	jammer=NULL;
	artillery=NULL;
	artillery2=NULL;  // fail safe
	player = GetPlayerHandle();

//  integers
	mission_state=0;
	scout_state=99;
	scout_counter=0;
	comp_team=2;
}



void scion02::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (IsOdf2(h,"fbrecy"))
	{
		recycler=h;
	}
	if (IsOdf2(h,"fbjas2"))
	{
		jammer_exists=true;
		jammer=h;
	}
	if ((IsOdf2(h,"fvars2")) && (artillery==NULL))
	{
		artillery=h;
	}
	if ((IsOdf2(h,"fvartl")) && (artillery==NULL))
	{
		artillery=h;
	}
	if ((IsOdf2(h,"fvars2")) && (artillery2==NULL))
	{
		artillery2=h;
	}
	if ((IsOdf2(h,"fvartl")) && (artillery2==NULL))
	{
		artillery2=h;
	}

/*
    if ((ant_mound == NULL) && (IsOdf2(h,"fbantm")))
	{
		ant_mound = h;
	}

	if ((tap == NULL) && (IsOdf2(h,"fbatap")))
	{
		tap = h;
	}
*/
}

void scion02::HandleScout(void)
{
	char tempstr[128];	
	scout_counter++;
	if ((scout_state>3) && (scout_counter%1500==0))
	{
		scout_state=0;
	}

	switch (scout_state)
	{
		case 0:
			if (mission_state>2)
			{
				scout=BuildObject("ivscout",comp_team,"spawn_scout1");  // may get stuck?
				Goto(scout,"scav_1");
			}
			else
			{
				scout=BuildObject("ivscout",comp_team,"spawn_scout2");  // may get stuck?
				Goto(scout,"tank_1");
			}
			oldscout=scout;
			scout_state++;
			break;
		case 1:
			if (!IsAlive(scout))
			{
				scout_state=4;
			}
			{
				Handle temp=GetNearestEnemy(scout);
				if ((GetDistance(scout,"scav_1")<100.0f) 
					|| (GetDistance(scout,"tank_1")<100.0f) 
					|| ((IsAlive(temp)) && (GetDistance(scout,temp)<75.0f))
					)
				{
					SetObjectiveOn(scout);
					TranslateString2(tempstr, sizeof(tempstr), "MissionS0203");  // Enemy Scout				
					SetObjectiveName(scout,tempstr);
					AudioMessage("scion0212.wav");  // a scout is within the perimeter, we must destroy it before he reports back
					Goto(scout,"epgen_1");
					scout_state++;
				}
			}
			break;
		case 2:
			if (GetDistance(scout,"epgen_1")<100.0f)
			{
				mission_state=101;
				AudioMessage("scion0220.wav");  // oh no we've been detected
				been_detected=true;
				
			}
			if (!IsAlive(scout))
			{
				scout_state=4;
			}
			break;
	}

}

void scion02::ArtilleryObjective(void) {
	ClearObjectives();
	if (art_objective1) {
		AddObjective("scion0205.otf",GREEN,5.0f);
	} else AddObjective("scion0205.otf",WHITE,5.0f);
	if (art_objective2) {
		AddObjective("scion0209.otf",GREEN,5.0f);
	} else AddObjective("scion0209.otf",WHITE,5.0f);

}

void scion02::Execute(void)
{





/*
	Here is where you put what happens every frame.  
*/
	// paths
	// spawn_scout1  >> strike1 
	// spawn_scout2  >> strike2
	
	//	SetCurAmmo(player,1500);//TEMP	
	//	SetCurHealth(player,2000);//TEMP
//STARTING PARAMETERS
	
	char tempstr[128];

	if ((!been_detected) && (mission_state<5)) // 5= ambush is set
	{
		/*
		Handle foe=GetWhoShotMe(player);
		if ((foe!=NULL) && (foe!=oldscout) && 
			(IsAlive(oldscout)) && // I just added this.. probably unness if HandleScout worked
			(GetTeamNum(oldscout)==comp_team))
		*/
		if ((GetDistance(enemytank1,player)<75.0f) ||
			(GetDistance(enemytank2,player)<75.0f) ||
			(GetDistance(enemyscout1,player)<75.0f) ||
			(GetDistance(enemyscout2,player)<75.0f))
		{
			been_detected=true;
			mission_state=101;
			AudioMessage("scion0220.wav");  // oh no we've been detected
			been_detected=true;
		}
		HandleScout();
	}
	


	switch (mission_state)
	{
		case 0:
			{
			// HACK to fix bug
				Handle shab=GetHandle("shabayev");  // what is she doing here anyway?
				RemoveObject(shab);

			// play message
				talk1 = AudioMessage("scion0201.wav");
		
			// take over base
				SetScrap(1,40);

			// Your starting base
				int grp=GetFirstEmptyGroup();			
				recycler=BuildObject("fvrec2",1,"recycler");
				SetGroup(recycler,grp);	

				grp++;
				scav1=BuildObject("fvscav",1,"scav_1");
				SetGroup(scav1,grp);
				grp++;
				scav2=BuildObject("fvscav",1,"scav_2");
				SetGroup(scav2,grp);	
			
				grp++;
				turret1=BuildObject("fvturr",1,"turret_1");
				SetGroup(turret1,grp);
				turret2=BuildObject("fvturr",1,"turret_2");
				SetGroup(turret2,grp);

				grp++;
				sent1=BuildObject("fvtank",1,"tank_1");
				SetGroup(sent1,grp);
				sent2=BuildObject("fvtank",1,"tank_2");
				SetGroup(sent2,grp);

				grp++;
				constructor=BuildObject("fvcos2",1,"cons_1");
				SetGroup(constructor,grp);

				objective=BuildObject("ibnav",1,"jammer");
//	These units have smaller engage ranges
				enemytank1=BuildObject("ivtas2",2,"etank_1");
				enemyscout1=BuildObject("ivscos2",2,"escout_1");	
	
				enemytank2=BuildObject("ivtas2",2,"etank_2");
				enemyscout2=BuildObject("ivscos2",2,"escout_2");

				Patrol(enemytank1,"isdf_patrol1",0);
				Patrol(enemyscout1,"isdf_patrol1",0);

				Patrol(enemytank2,"isdf_patrol2",0);
				Patrol(enemyscout2,"isdf_patrol2",0);

				BuildObject("ibgtow",comp_team,"egtow_1");
				BuildObject("ibgtow",comp_team,"egtow_2");
				power1=BuildObject("ibpgen",comp_team,"epgen_1");
				power2=BuildObject("ibpgen",comp_team,"epgen_2");
				BuildObject("ibsbay",comp_team,"esbay");
				BuildObject("ibfact",comp_team,"efact");
				enemybase=BuildObject("ibrecy",comp_team,"erecy");
				BuildObject("ibarmo",comp_team,"earmo");

				base_unit_1=BuildObject("ivtank",comp_team,"base_unit_1");
				base_unit_2=BuildObject("ivmisl",comp_team,"base_unit_2");
				base_unit_3=BuildObject("ivtank",comp_team,"base_unit_3");
				base_unit_4=BuildObject("ivmisl",comp_team,"base_unit_4");
				
				mission_state++;
			}
			break;
		case 1:  // further instruction
			if ((IsAudioMessageDone(talk1)))
			{
					ClearObjectives();
					AudioMessage("scion0202.wav");
					AddObjective("scion0201.otf",WHITE,20.0f);
					SetObjectiveOn(objective); 
					TranslateString2(tempstr, sizeof(tempstr), "MissionS0201");  // Ambush
					SetObjectiveName(objective,tempstr);
					mission_state++;
			}
			break;
		case 2:  // player arrives at ambush site
			if (GetDistance(player,objective)<75.0f)	
			{
				AudioMessage("scion0203.wav");  // good now set up
				ClearObjectives();
				AddObjective("scion0202.otf",WHITE,20.0f);
				AddObjective("scion0203.otf",WHITE,20.0f);
				mission_state++;

			}
			break;
		case 3: // wait for the constructor to show up
				if (GetDistance(constructor,objective)<75.0f)
				{	
					AudioMessage("scion0204.wav"); // Good, now build a jammer
					ClearObjectives();
					AddObjective("scion0202.otf",GREEN,5.0f);
					AddObjective("scion0203.otf",WHITE,5.0f);
					mission_state++;
				}
			break;
		case 4:
				if (jammer_exists)
				{
					AudioMessage("scion0205.wav");  
					// now drive into the enemy base and lead them to 
					// your ambush.  
					ClearObjectives();
					AddObjective("scion0204.otf",WHITE,10.0f);
					mission_state++;
					SetIndependence(enemytank1,1);
					SetIndependence(enemytank2,1);
					SetIndependence(enemyscout1,1);
					SetIndependence(enemyscout2,1);
					been_detected=true;  // doesn't matter now
				}
			break;
		case 5: 
			if ((GetDistance(player,base_unit_1)<200.0f) ||
				(GetDistance(player,base_unit_2)<200.0f)
				|| (GetDistance(player,enemytank1)<75.0f)
				|| (GetDistance(player,enemyscout1)<75.0f))
			{
				AudioMessage("scion0206.wav");
				// Here they come!
				Goto(base_unit_1,"go_jammer");
				Goto(base_unit_2,"go_jammer");
				Goto(base_unit_3,"go_jammer");
				Goto(base_unit_4,"go_jammer");
				Attack(enemyscout1,player);
				Attack(enemytank1,player);
				// the ambush has begun
				mission_state++;
			}
			break;
		case 6: // wait for ambush to end
			if (!IsAlive(player))
			{
				if (IsAlive(base_unit_1))  
					Attack(base_unit_1,jammer);
				if (IsAlive(base_unit_2))
					Attack(base_unit_2,jammer);
				if (IsAlive(base_unit_3))
					Attack(base_unit_3,jammer);
				if (IsAlive(base_unit_4))
					Attack(base_unit_4,jammer);
				if (IsAlive(enemyscout1))
					Attack(enemyscout1,player);
				if (IsAlive(enemytank1))
					Attack(enemytank1,player);
			}
			if ((!IsAlive(base_unit_1)) &&
				(!IsAlive(base_unit_2)) &&
				(!IsAlive(base_unit_3)) &&
				(!IsAlive(base_unit_4)))
			{
				AudioMessage("scion0207.wav");
				ArtilleryObjective();
				/*
					Now we will use artillery
					to finish off the base surgically
				*/
				// set where the artillery goes as an objective, 
				// wait for the player to build it
				SetObjectiveOff(objective);
				objective2=BuildObject("ibnav",1,"escout_1");
				SetObjectiveOn(objective2);
				TranslateString2(tempstr, sizeof(tempstr), "MissionS0202");  // Artillery
				SetObjectiveName(objective2,tempstr);
				mission_state++;
			}
			break;
		case 7:  // wait for artillery
			if ((IsAlive(artillery)) || (IsAlive(artillery2)))
			{
				AudioMessage("scion0208.wav");
				art_objective1=true;
				ArtilleryObjective();
				mission_state++;
			}
			break;
		case 8:  // wait for it to get there
			if (
				((IsAlive(artillery2)) && (GetDistance(artillery,objective2)<50.0f)) || 
				((IsAlive(artillery2)) && (GetDistance(artillery2,objective2)<50.0f))  ) 
			{
				art_objective2=true;
				ArtilleryObjective();
				AudioMessage("scion0209.wav");
				SetObjectiveOn(power1);
				SetObjectiveOn(power2);
				mission_state++;
			}
			break;
		case 9:
			increment++;
			if (increment%300==0)
			{
				if (!last_objective) {
					ClearObjectives();
					AddObjective("scion0206.otf",WHITE,5.0f);
					last_objective=true;
				}
				Handle atk1=BuildObject("ivscout",2,"base_unit_2");
				Attack(atk1,artillery);
			}
			if ((!IsAlive(power1)) || (!IsAlive(power2)))
			{
				AudioMessage("scion0210.wav");
				if (IsAlive(power1))
					SetObjectiveOff(power1);
				if (IsAlive(power2))
					SetObjectiveOff(power2);
				mission_state++;
			}
			break;
		case 10:
			if (GetDistance(player,"erecy")<75.0f)
			{
				AudioMessage("scion0211.wav");
				SucceedMission(GetTime()+10.0f,"scion02w1.txt");
				mission_state++;
			}
			break;
		case 101:  // player is detected too soon
			{
				increment++;
				if (increment%300==0)
				{
					Handle atk=BuildObject("ivtank",comp_team,"efact");
					Attack(atk,recycler);
					atk=BuildObject("ivmbike",comp_team,"efact");
					Attack(atk,recycler);
					atk=BuildObject("ivrckt",comp_team,"spawn_scout1");
					Goto(atk,"strike1");
				}
			}
			break;
		case 102:
			/*
				You lose, movie etc.  

			*/
			{
				FailMission(GetTime()+15.0f,"scion0201.otf");
				mission_state++;
			}
			break;
	}
				


	//making sure isdf base guardians stay in the area
/*
	if ((!tank1toofar) && (GetDistance(basetank1,"goback") > 250))
	{
		Retreat(basetank1,"goback");
		tank1toofar = true;
	}

	if ((!tank2toofar) && (GetDistance(basetank2,"goback") > 250))
	{
		Retreat(basetank2,"goback");
		tank2toofar = true;
	}

	if ((!scout1toofar) && (GetDistance(scout1,"goback") > 250))
	{
		Retreat(scout1,"goback");
		scout1toofar = true;
	}

///
	if ((tank1toofar) && (GetDistance(basetank1,"goback") <100))
	{
		Attack(basetank1,player);
		tank1toofar = false;
	}
	
	if ((tank2toofar) && (GetDistance(basetank2,"goback") <100))
	{
		Attack(basetank2,player);
		tank2toofar = false;
	}

	if ((scout1toofar) && (GetDistance(scout1,"goback") <100))
	{
		Attack(scout1,player);
		scout1toofar = false;
	}
*/
	if ((mission_state<102) && (!IsAlive(recycler)))
	{
		mission_state=102;
	}
	player = GetPlayerHandle();

}

