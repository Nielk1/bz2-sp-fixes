#include "..\Shared\SPMission.h"

class isdf08Mission : public SPMission 
{
public:
	isdf08Mission(void)
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
	void Execute(void);

	// bools
	bool
		b_first,
		start_done,
		shab_still,
    trigger1,
    trigger2,
    turret_attacked,
    patrol_attacked,
    reached_base,
    inside_espir1,
    inside_scout1,
		inside_scout2,
    inside_scout3,
    killed_attack1,
    killed_attack2,
    inside_turret1,
    inside_turret2,
	detected,
    played_0802,
    played_0803,
    played_0804,
    played_0805,
    played_0806,
    played_0807,
    played_0808,
    played_0809,
	played_0810,
    played_0811,
    played_0812,
	jak1_attack,
	jak2_attack,
	jak3_attack,
	jak4_attack,
	jak5_attack,
	edge_attack,
    b_last;

	// floats
	float
		f_first,

		f_last;

	// handles
	Handle
		h_first,
		player,
		turret1,
		turret2,
		attack1,
		attack2,
		attack3,
		rescue1,
		rescue2,
		rescue3,
		scout1,
		scout2,
		scout3,
    pilot1,
    pilot2,
    pilot3,
    pilot4,
    pilot5,
    pilot6,
    pilot7,
    pilot8,
    espir1,
    message1,
    jak1,
    jak2,
    jak3,
    jak4,
    jak5,
    jak7,
		fvartl,
		shab,
		first_aud,
		h_last;

	// integers
	int
		i_first,

		i_last;
};
DLLBase * BuildMission(void)
{
	return new isdf08Mission();
}

void isdf08Mission::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	start_done = false;
  trigger1 = false;
  trigger2 = false;
  turret_attacked = false;
  patrol_attacked = false;
  reached_base = false;
  inside_espir1 = false;
  inside_scout1 = false;
  inside_scout2 = false;
  inside_scout3 = false;
  killed_attack1 = false;
  killed_attack2 = false;
	inside_turret1 = false;
	inside_turret2 = false;
	played_0802 = false;
	played_0803 = false;
	played_0804 = false;
	played_0805 = false;
	played_0806 = false;
	played_0807 = false;
	played_0808 = false;
	played_0809 = false;
	played_0810 = false;
	played_0811 = false;
	played_0812 = false;
	jak1_attack=false;
	jak2_attack=false;
	jak3_attack=false;
	jak4_attack=false;
	jak5_attack=false;
	detected=false;
	shab_still=false;
	edge_attack=false;
//  floats


//  handles
	player = GetPlayerHandle();



//  integers

	/*
		edge_warning1
		edge_warning2
		fvartl
	*/

}

void isdf08Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

/*
	if ((scav1 == NULL) && (IsOdf2(h,"ivscav")))
	{
		scav1 = h;
	}
	else if ((scav2 == NULL) && (IsOdf2(h,"ivscav")))
	{
		scav2 = h;
	}
	else if ((turret1 == NULL) && (IsOdf2(h,"ivturr")))
	{
		turret1 = h;
	}
	else if ((turret2 == NULL) && (IsOdf2(h,"ivturr")))
	{
		turret2 = h;
	}
	else if ((wingman1 == NULL) && (IsOdf2(h,"ivscout")))
	{
		wingman1 = h;
	}
	else if ((wingman2 == NULL) && (IsOdf2(h,"ivscout")))
	{
		wingman2 = h;
	}
*/
}

void isdf08Mission::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/

	player = GetPlayerHandle();
	char tempstr[128];

	if (!start_done)
	{
		shab=GetHandle("shabayev");
		start_done=true;
		Handle temp=BuildObject("ibnav",1,"manson_base");
		TranslateString2(tempstr, sizeof(tempstr), "Mission0801");  // West Base
		SetObjectiveName(temp,tempstr);
		GiveWeapon(player, "igsatc");
		first_aud=AudioMessage("mes0801.wav");  // was isdf0801
// I don't know what these are or where they go
/*
	Handle sp=BuildObject("fvtank",2,"spawn1");
		SetSkill(sp,3);
		sp=BuildObject("fvsent",2,"spawn2");
		SetSkill(sp,3);
		sp=BuildObject("fvtank",2,"spawn3");
		SetSkill(sp,3);
		sp=BuildObject("fvsent",2,"spawn4");
		SetSkill(sp,4);
		SetScrap(1,30);
*/	
// These ships circle the ruin you're in at the beginning, then leave
		pilot1=BuildObject("fvtank",2,"pilot_1");
		pilot2=BuildObject("fvtank",2,"pilot_2");
		pilot3=BuildObject("fvsent",2,"pilot_3");

// They are dumb
		SetIndependence(pilot1,0);
    SetIndependence(pilot2,0);
    SetIndependence(pilot3,0);

// These are the patrol paths for the vehicles
    Goto(pilot1,"start1");
    Goto(pilot2,"start2");
    Goto(pilot3,"start3");

// These turrets block the path to the south
    turret1=BuildObject("fvturr",2,"turret_1");
		turret2=BuildObject("fvturr",2,"turret_2");

// These jaks inhabit the swamp just west of the starting point
		jak1=BuildObject("mcjak01",0,"jak_1");
		Patrol(jak1,"jakpatrol1",1);
		SetIndependence(jak1,1);
    jak2=BuildObject("mcjak01",0,"jak_2");
		Patrol(jak2,"jakpatrol2",1);
		SetIndependence(jak2,1);
    jak3=BuildObject("mcjak01",0,"jak_3");
		Patrol(jak3,"jakpatrol3",1);
		SetIndependence(jak3,1);

// This spire guards the entrance to the Scion base
    espir1=BuildObject("fbspir",2,"espir_1");
 //   SetIndependence(espir1,0);

// These 3 ships patrol different areas
    scout1=BuildObject("fvtank",2,"patrol_1");
		Patrol(scout1,"patrol_1",0);
		scout2=BuildObject("fvtank",2,"patrol_2");
		Patrol(scout2,"patrol_2",0);

		// this should be a bazooka or something
		BuildObject("aptech",0,"weapon_1");

// pilots around second patrol ship
#if 0
		// 'sssold' won't save/reload properly - NM 9/28/04
		pilot7=BuildObject("sssold",2,"pilot_5");
    Patrol(pilot7,"pilotpatrol1",0);
		pilot8=BuildObject("sssold",2,"pilot_6");
    Patrol(pilot8,"pilotpatrol2",0);
#endif

		// jak blocking power ups before ruins
		jak7=BuildObject("mcjak01",0,"jak_7");
    Patrol(jak7,"jakpatrol7",1);

		// power up in the second nest of puff plants
		BuildObject("aprepa",0,"health_1");
		BuildObject("apammo",0,"ammo_1");
		BuildObject("apbazo",0,"weapon1");

// jak creatures hanging around ruins
		jak4=BuildObject("mcjak01",0,"jak_4");
    Patrol(jak4,"jakpatrol4",1);
		jak5=BuildObject("mcjak01",0,"jak_5");
    Patrol(jak5,"jakpatrol5",1);

		// power ups near ruins
		BuildObject("aprepa",0,"health_2");
		BuildObject("apammo",0,"ammo_2");
		SetAnimation(shab,"speak");
		fvartl=BuildObject("fvartl",2,"fvartl");
	}

	if ((IsAudioMessageDone(first_aud)) && (!shab_still))
	{
		shab_still=true;
		SetAnimation(shab,"speak",1);
	}
	if ((!IsAround(shab)) && (!reached_base))
	{
		FailMission(GetTime()+5.0f,"genFail.txt");
		reached_base=true;

	}
// Gun tower shoots at you if you get within 100 meters
  if (inside_espir1)
  {
    if (GetDistance(espir1,player) > 50.0f)
    {
      inside_espir1=false;
      Stop(espir1);
    }
  }
  else
  {
    if (GetDistance(espir1,player) < 50.0f)
    {
      inside_espir1 = true;
      Attack(espir1,player);
    }
  }

  if ((!jak1_attack) && (GetDistance(jak1,player)<50.0f))
  {
	  jak1_attack=true;
	  Stop(jak1,player);
  }
  if ((!jak2_attack) && (GetDistance(jak2,player)<50.0f))
  {
		jak2_attack=true;
		Stop(jak2,player);
  }
  if ((!jak3_attack) && (GetDistance(jak3,player)<50.0f))
  {
	  jak3_attack=true;
	  Stop(jak3,player);
  }
  if ((!jak4_attack) && (GetDistance(jak4,player)<50.0f))
  {
	  jak4_attack=true;
	  Stop(jak4,player);
  }
   if ((!jak5_attack) && (GetDistance(jak5,player)<50.0f))
  {
	  jak5_attack=true;
	  Stop(jak5,player);
  }
// If you shoot any of the patrol ships in the beginning, they will attack you
  if (((GetWhoShotMe(pilot1)  ==  player) ||
      (GetWhoShotMe(pilot2)  ==  player)  ||
      (GetWhoShotMe(pilot3)  ==  player))  &&
      (!patrol_attacked))
  {
    Attack(pilot1,player);
    Attack(pilot2,player);
    Attack(pilot3,player);
    patrol_attacked=true;
  }

// Once the patrol from the beginning leaves the ruins, they disappear from the map
  if ((GetDistance(pilot1,"killpatrol1")<64.0f))
  {
    RemoveObject(pilot1);
  }

  if ((GetDistance(pilot2,"killpatrol1")<64.0f))
  {
    RemoveObject(pilot2);
  }

  if ((GetDistance(pilot3,"killpatrol1")<64.0f))
  {
    RemoveObject(pilot3);
  }

  if (((GetDistance(pilot1,"turret_1")<192.0f)  ||
       (GetDistance(pilot2,"turret_1")<192.0f)  ||
       (GetDistance(pilot3,"turret_1")<192.0f))  &&
       (!played_0802))
  {
//		message1=AudioMessage("isdf0802.wav");
		ClearObjectives();
		AddObjective("isdf0801.otf",WHITE,15.0f);
		played_0802=true;
  }

  if ((played_0802)  &&  (IsAudioMessageDone(message1))  &&
      (GetDistance(player,"start_point")<20.0f)  &&  (!played_0803))
  {
//    AudioMessage("isdf0803.wav");
    played_0803=true;
  }

  if ((!played_0804)  &&  (played_0802)  &&  (GetDistance(player,"play_0804")<80.0f))
  {
    AudioMessage("isdf0804.wav");
    played_0804=true;
  }

  if ((!played_0805)  &&  (played_0802)  &&  (GetDistance(player,"play_0805")<80.0f))
  {
    AudioMessage("isdf0805.wav");
    played_0805=true;
  }

  if ((GetDistance(player,turret1)<150.0f)    &&
      (!played_0806))
  {
    AudioMessage("isdf0806.wav");
    played_0806=true;
  }

  if ((!played_0807)  &&  (GetDistance(player,"sees_datatransfer")<100.0f))
  {
    AudioMessage("isdf0807.wav");
    played_0807=true;
    ClearObjectives();
    AddObjective("isdf0801.otf",WHITE,10.0f);
  }


// As you exit the ruins, 3 Scion ships spawn in the Scion base and head towards you
	if (((GetDistance(player,"exitruin_1")<80.0f)  ||
      (GetDistance(player,"exitruin_2")<80.0f))  &&
      (!trigger1))
  {
    attack1=BuildObject("fvtank",2,"attack_1");
    attack2=BuildObject("fvsent",2,"attack_2");
    attack3=BuildObject("fvtank",2,"attack_3");
    Attack(attack1,player);
    Attack(attack2,player);
    Attack(attack3,player);
    trigger1=true;
  }

  if ((trigger1)  &&  (!played_0808))
  {
    AudioMessage("isdf0808.wav");
    played_0808=true;
  }

  if (((GetDistance(player,attack1)<300.0f)  ||
      (GetDistance(player,attack2)<300.0f)  ||
      (GetDistance(player,attack3)<300.0f))  &&
      (!played_0809))
  {
    AudioMessage("isdf0809.wav");
    played_0809=true;
  }

#if 0
	// isdf0811.wav doesn't exist - NM 11/14/03
  if (((GetDistance(player,attack1)<100.0f)  ||
      (GetDistance(player,attack2)<100.0f)  ||
      (GetDistance(player,attack3)<100.0f))  &&
      (!played_0811))
  {
    AudioMessage("isdf0811.wav");
    played_0811=true;
  }
#endif

// If you head south, the turrets will kill you
  // if I am between entering the swamp and
  // I hide in water (near swampn) then the patrols ignore me
  if ((played_0804) &&
	  (!trigger2))
  {	
	  if ((GetDistance(player,"swamp1")<50.0f) ||
			(GetDistance(player,"swamp2")<50.0f) ||
			(GetDistance(player,"swamp3")<50.0f) ||
			(GetDistance(player,"swamp4")<50.0f) ||
			(GetDistance(player,"swamp5")<50.0f) ||
			(GetDistance(player,"swamp6")<50.0f) ||
			(GetDistance(player,"swamp7")<50.0f))
	  {
		  SetPerceivedTeam(player,2);
		  SetIndependence(scout1,0);
		  SetIndependence(scout2,0);
	  }
		else
	  {
		  SetPerceivedTeam(player,1);
		  SetIndependence(scout1,1);
		  SetIndependence(scout2,1);
		}
		if ((!detected) && 
			((GetWhoShotMe(scout1)==player) 
				||(GetWhoShotMe(scout2)==player)))
		{
			Attack(scout1,player);
			Attack(scout2,player);
			detected=true;
		}
	
  }
 // As you approach the ISDF base, 3 friendly units launch to protect you from the Scion attackers
  if (((GetDistance(player,"enterbase_1")<100.0f)  ||
      (GetDistance(player,"enterbase_2")<100.0f)  ||
      (GetDistance(player,"enterbase_3")<100.0f))  &&
      (!trigger2))
  {
    rescue1=BuildObject("ivtank",1,"rescue_1");
    rescue2=BuildObject("ivmbike",1,"rescue_2");
    rescue3=BuildObject("ivtank",1,"rescue_3");
    Attack(rescue1,attack1);
    Attack(rescue2,attack1);
    Attack(rescue3,attack1);
    trigger2=true;
  }

  if ((!IsAlive(attack1))  &&
      (!killed_attack1))
  {
    Attack(rescue1,attack2);
    Attack(rescue2,attack2);
    Attack(rescue3,attack2);
    killed_attack1=true;
  }

  if ((!IsAlive(attack2))  &&
      (!killed_attack2))
  {
    Attack(rescue1,attack3);
    Attack(rescue2,attack3);
    Attack(rescue3,attack3);
    killed_attack2=true;
  }



  if ((GetDistance(player,"edge_warning1")<25.0f)
	  && (GetDistance(player,"edge_warning1")<25.0f)
	  && (!edge_attack))
  {
		edge_attack=true;
		Attack(fvartl,player);
  }
// If the ISDF ships get close to the Scion attack squadron, the Scions will stop chasing you and fight the ships
  if ((GetDistance(rescue1,attack1)<50.0f)  ||
      (GetDistance(rescue1,attack2)<50.0f)  ||
      (GetDistance(rescue1,attack3)<50.0f)  ||
      (GetDistance(rescue2,attack1)<50.0f)  ||
      (GetDistance(rescue2,attack2)<50.0f)  ||
      (GetDistance(rescue2,attack3)<50.0f)  ||
      (GetDistance(rescue3,attack1)<50.0f)  ||
      (GetDistance(rescue3,attack2)<50.0f)  ||
      (GetDistance(rescue3,attack3)<50.0f))
  {
    Attack(attack1,rescue1);
    Attack(attack2,rescue2);
    Attack(attack3,rescue3);
  }

// If you've killed all the attack vehicles and entered the base, the mission is a success
  if 
	  (((GetDistance(player,"endmission1")<100.0f)  ||
      (GetDistance(player,"endmission2")<100.0f))  &&
      (!IsAlive(attack1))  &&
      (!IsAlive(attack2))  &&
      (!IsAlive(attack3))  &&
      (!reached_base))
	
  {
		AudioMessage("isdf0514.wav");
		SucceedMission(GetTime()+10.0f,"isdf08w1.txt");
		reached_base=true;
  }
}
