#include "..\Shared\SPMission.h"
/*
  Mission 9

	  R U M B L E 
		I N
		T H E
	  J U N G L E
*/ 



class isdf09 : public SPMission 
{
public:
	isdf09(void)
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
	void ShowObjectives();
	void Execute(void);

	// bools
	bool
		b_first,
		botched_rescue,
		start_done,
		b_last;

	// floats
	float
		f_first,
		shab_message,
		get_going,
		machine_time1,
		machine_time2,
		f_last;

	// handles
	Handle
		h_first,
		aud,
		apc1,
		player,
		ruin,
		objective,
		atk1,
		atk2,
		shabayev,
		nav,
		machine,
		crystal,
		turr1,
		turr2,
		turr3,
		turr4,
		h_last;


	// integers
	int
		i_first,
		shab_state,   // your progress in rescuing shab, independent of the mission
		mission_state,  // your progree in the mission
		ruin_cam,
		i_last;
};
DLLBase * BuildMission(void)
{
	return new isdf09();
}

void isdf09::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	botched_rescue=false;

	
//  floats
	shab_message=GetTime()+95.0f;  // was 30
	get_going=370.0f;  // get going to that base Sgt!
	
//  handles
	ruin=GetHandle("ruins");
	objective=GetHandle("objective");


//  integers
	mission_state=0;
	shab_state=0;


	/*
		PATH NOTES
		new_gun1
		new_gun2  2 points paths to build gun towers on
		shab_stay Build Shabayev there
		isdf_base1  in the base
 
	*/
}

void isdf09::AddObject(Handle h)
{
}

void isdf09::ShowObjectives()
{
	ClearObjectives();
	AddObjective("isdf0901.otf",WHITE,15.0f);
	if (mission_state<1)
	{
		AddObjective("isdf0902.otf",WHITE,15.0f);
		AddObjective("isdf0903.otf",WHITE,15.0f);
	}
	else
	{
		AddObjective("isdf0902.otf",GREEN,15.0f);
		if (mission_state<2)
		{
			AddObjective("isdf0903.otf",WHITE,15.0f);
		}
		else
			AddObjective("isdf0903.otf",GREEN,15.0f);

	}
}

#pragma warning (error : 4700) // local variable 'foo' used without having been initialized
#pragma warning (error : 4701) // local variable 'foo' may used without having been initialized


void isdf09::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/
	player=GetPlayerHandle();
	if (!start_done)
	{
		
		AudioMessage("isdf0904.wav");
		/*		MANSON
				Surviving that march through
				the jungle shows you've got some
				moxie.  
		*/		
		AudioMessage("isdf0905.wav");
		/*
				I've decided to strike at the scion
				base you discovered.  
				Unfortunantely the base is surrounded 
				by thick jungles and high canyon walls.  

				Attacking from the ground will be too
				difficult.  We should use this as an
				opportunity to test our new experimental
				flying APCs.  
		*/
		
		AudioMessage("isdf0906.wav");
		/*
			Take a small force to the edge of the base.  
				Once you get close I'll assign a squadron
				of APCs to your command.  

				When you get close enough to find a safe landing 
				zone inside the base.  Send the APCs into 
				the base.  

				This will be extremely dangerous.  
		*/
		nav=BuildObject("ibnav",1,"shab_def_spawn");
		SetObjectiveName(nav,"Shabayev");

		shabayev=BuildObject("ispilo",1,"shab_stay");  // let's see if that works.  


		machine= GetHandle("unnamed_mbdata00");
		crystal= GetHandle("power_crystal");

		turr1=GetHandle("base_turr1");
		turr2=GetHandle("base_turr2");
		turr3=GetHandle("base_turr3");
		turr4=GetHandle("base_turr4");

		Patrol(shabayev,"shab_stay");
		Handle sent=BuildObject("fvsent",2,"fury_patrol1");
		Patrol(sent,"fury_patrol1");
		sent=BuildObject("fvsent",2,"fury_patrol2");
		Patrol(sent,"fury_patrol2");

		// We got tha boom
		sent=BuildObject("fvtank",2,"defend1");
		Goto(sent,"strike2");
		sent=BuildObject("fvtank",2,"defend1");
		Goto(sent,"strike2");
		ShowObjectives();

		SetPlan("isdf09.aip",2);
		SetScrap(1,60);  // so its always the same
		start_done=true;
	}
	if ((shab_state<6) && (GetDistance(player,ruin)<200.0f)
		&& (!botched_rescue))
	{
		char ODFName[64];
		GetObjInfo(player, Get_CFG, ODFName);

		if (IsOdf2(player,"isuser"))  // the player needs wheels to resuce
		{
			atk1=BuildObject("fvsent",2,"shab_attack");
			shab_state=4;
			Attack(atk1,shabayev);
			botched_rescue=true;
		}
		else
		{

			// Cooke you're approaching 
			// my position.
			AudioMessage("isdf0909.wav");
			shab_state=6;
		}
	}

	switch (shab_state) {
		case 0:  // first message
			{ // so it is ok with temp 
				Handle temp;
				if (IsAlive(player))
					temp = GetNearestEnemy(player);
				if ((GetTime()>shab_message)
					&& (GetDistance(temp,player)>100.0f))
				{
					aud=AudioMessage("isdf0730.wav");  // was 0901
					// SHABAYEV
					// Cook, are you out there?  
					// I'm still at ruin. 
					shab_message=GetTime()+360.0f; // was 100
					CameraReady();
					shab_state++;
				}	
			}
			break;
		case 1: // second message
			if (!IsAudioMessageDone(aud))
			{
				CameraObject(shabayev,25,2,8,shabayev); // was -15
			}
			else
			{
				CameraFinish();
			}

			if (GetTime()>shab_message)
			{
				Handle sent=BuildObject("fvtank",2,"defend1");
				Goto(sent,"strike1");
				sent=BuildObject("fvtank",2,"defend1");
				Goto(sent,"strike1");
				AudioMessage("isdf0903.wav");
				// SHABAYEV
				// Cooke are you still alive?  
				// Perhaps you could have your
				// friend Manson send someone to 
				// pick me up.  
				shab_message=GetTime()+450.0f;  // was 100
				shab_state++;
			}
		case 2:
			if (GetTime()>shab_message)
			{
				AudioMessage("isdf0733a.wav");   // Cooke come quickly, was 0901
				// SHABAYEV
				// All units!  This is leutenant Shabayev
				// I'm trapped in the ruins to the east
				// of our main base.  I need assistance.  
				shab_message=GetTime()+390.0f;  
				shab_state++;
			}
			break;
		case 3:
			if (GetTime()>shab_message)
			{
				// now things get desperate
				SetTeamNum(ruin,1);
				SetCurHealth(ruin, static_cast<long>(0.1f * GetMaxHealth(ruin)));
 				atk1=BuildObject("fvsent",2,"shab_attack");
				atk2=BuildObject("fvsent",2,"shab_attack");
				Attack(atk1,shabayev);
				Attack(atk2,shabayev);
				shab_state++;
			}
			break;
		case 4:
			if (ruin_cam>0)
			{
				CameraObject(shabayev,20,6,12,shabayev);
				ruin_cam++;
				if (ruin_cam==75)
				{
					CameraFinish();
					shab_state++;
				}
			}
			if (((GetDistance(atk1,shabayev)<75.0f) || (GetDistance(atk2,shabayev)<75.0f))
				&& (ruin_cam==0))
			{
				AudioMessage("isdf0912.wav");
				// Shabayev
				// They found me!
				/*
					Cineractive on ruin dying
				*/
				CameraReady();
				ruin_cam=1;
			}
			break;
		case 5:
			if (!IsAlive(shabayev))
			{
				AudioMessage("isdf0913.wav");
				// Shabayev
				// I'm dead!
				shab_state=999;
				FailMission(GetTime()+5.0f,"isdf09l1.txt");
			}
			break;
		case 6:
			// you to the rescue
			if (GetDistance(player,ruin)<75.0f)
			{
				// Cineractive and end..
				AudioMessage("isdf0915.wav");
				/*
					Put a cineractive in here
				*/
				RemoveObject(nav);
				RemoveObject(shabayev);
				shab_state++;
			}
			break;

		/*
			If you wait to long
			units from
			shab_attack
			blow up her building and
			kill her.  
		*/
	}

	switch (mission_state) {
		case 0:  //opening cineractive..
			if (GetTime()>get_going)
			{
				AudioMessage("isdf0907.wav");
				// 
				// Cooke!  I thought you said you 
				// knew where that base was!  
				// Well?  Get over there!  
				get_going=99999.0f;

			}
			if (GetDistance(player,objective)<250.0f)
			{
				AudioMessage("isdf0908.wav");
				// That's it!  Send in the APCs!
				int grp=GetFirstEmptyGroup();

				apc1=BuildObject("ivapc",1,"spawn_apc");
				Handle apc2=BuildObject("ivapc",1,"spawn_apc");	
				SetGroup(apc1, grp);
				SetGroup(apc2,grp);
				Handle tank=BuildObject("fvtank",2,"defend1");
				Patrol(tank,"defend_patrol");
				BuildObject("fvtank",2,"defend1");
				mission_state++;
				ShowObjectives();

				SetObjectiveOn(objective);
			}
			break;
		case 1:  // APCs attacking
			if (GetDistance(apc1,objective)<250.0f)
			{
				AudioMessage("avapcvj.wav");
				// APCs ready to attack
				// AudioMessage("isdf0911.wav");
				// Soldier
				// Let's get them!
				mission_state++;
			}
			else
			
				if (!IsAlive(objective))
				{
					// in case you do it without the apcs
					mission_state++;
				}
			
			break;
		case 2:
			if ((!IsAlive(objective))
				&& (!IsAlive(turr1)) && (!IsAlive(turr2)) && 
				(!IsAlive(turr3)) && (!IsAlive(turr4))
				)
			{
				aud=0;
	//			AudioMessage("isdf0914.wav");
				ClearObjectives();
				AddObjective("isdf0904.otf",WHITE,10.0f);
				if (shab_state!=7)
				{
					AudioMessage("isdf0901.wav");
				}
				mission_state++;
			}
			break;
		case 3:  // end cineractive
			if ((aud==0) && (shab_state==7))
			{
				aud=AudioMessage("isdf0914.wav");  // Congrats on clearing the base
				
				ShowObjectives();
			}
			if ((shab_state==7) && (IsAudioMessageDone(aud))){
				machine_time1=GetTime()+20.0f;
				AudioMessage("cin0601.wav");
				CameraReady();
				mission_state++;

			}

			break;
		case 4:
			if (GetTime()<machine_time1) {
				CameraPath("end_camera_path",10,250,machine);
			}
			else {
				machine_time2=GetTime()+12.0f;
				mission_state++;
			}
			break;
		case 5:
			if (GetTime()<machine_time2) {
				CameraPath("crystal_camera",60,0,crystal);
			}
			else {

				SucceedMission(GetTime()+20.0f,"isdf09w1.txt");
				CameraFinish();
				mission_state++;
			}
			break;

	}
		

}

