//****//
//TODO--Clean up the removed praises from Shab near the beginning (there's some unnecessary script)
//****//
//TODO make a special scout odf that does not objectify targets (for the AI scouts)
//TODO (this is in, but the path points need to be adjusted ) make it so if player jumps out of his tank near the ruins, several Jaks spawn to attack him
//TODO i lessened the health on the tug, test this out. was 10000 now 7000

#include "..\Shared\SPMission.h"

class scion01 : public SPMission 
{
public:
	scion01(void)
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
	bool PostLoad(bool missionSave);
	void Execute(void);

	// bools
	bool
		b_first,
		missionstart,
		rondevous1,
		convoygo1,
		escort1afarahead,escort1aclose,
		missionwon,
		engage_escorts,
		ambush1over,rdycam1,
		ambushers1killed,
		escort1a_look,
		escort1b_look,
		tug_moveout_nav2,intro_rdycam1,
		playermorphed,playernotmorphed,
		vo1,vo2,vo3,vo6,vo7,vo19,check1,shot3_settime,
		warned1,warned2,morphdrill,begin_rockslide_sequence,
		shabgopatrol,rockslide_shot1,rockslide_shot2_settime,rockslide_shot3_settime,
		baseattack1,vo8,shabdead,escortcall,vo10,toolong1,cooknotaround,vo16,objectifynav1,
		escortsgoinghome,attack2,vo7B,vo8B,jaksgo,jakstop1,jakstop2,tugkilled,routeattack1,
		routeattack2,rockslide,rockslideambush,vo20,rockslideambushersdead,obj7,
		playeronfoot,vo22,rondevous2,leave,convoygo2,escort2afarahead,escort2aclose,
		winmission,obj8,obj9,kill1,kill2,playerjumpgun1,toolong2,failtooktoolong,attack3,
		vo7C,vo8C,attack4,vo7D,vo8D,ambush1spawn,vo23,delay2,tugpickuppower,powerkilled,
		playeratnav1,vo25,obj11,praise1,praise2,praise3,praise4,rockslide_sequence_over,
		playersrecy_dead,vo_recydead,obj12,tug_at_rockslide,player_at_rockslide,
		cin1over,rockslide_shot1_over,rockslide_shot2,rockslide_shot2_over,rockslide_shot3,rockslide_shot3_over,
		intro_shot1over,intro_shot2over,shot2_settime,intro_shot3over,
		intro_shot4over,shot4_settime,obj13,
		pilots_move2,cons_move1,cons_move2,shab_relook,
		settime_vo6,setvo2time,
		lung_built,vo34,
		got_lungs,camcancelled_vo1,
		checkmsg21done,
		playsound1,playsound2,playsound3,playsound4,dropship_sequence_over,
		land,
		vo35,
		obj10,swap,doors_open,move_into_dropship,remove_escort2a,remove_escort2b,remove_tug1,
		remove_power,all_aboard,dropship_shot1,dropship_rdycam1,dropship_endcin,
		move_into_dropship2,move_into_dropship3,
		msg6_stop,swap_rockslide1,
		on_foot_cin_over,
		on_foot_shot1,setup_on_foot_shot1,
		pilo_go1,pilo_stop1,
		on_foot_shot2,setup_on_foot_shot2,amini_go,
		on_foot_shot3,pilo_go2,
		suprise_jaks,
		too_long_build_lung,
		take_off_sound,
		b_last;

	// floats
	float
		f_first,
		escort_reaction_time,
		delay1_time,
		vo1time,
		vo2time,
		vo3time,
		vo6time,
		vo7time,
		toolongtomorph,
		toolongtomorph2,
		baseattack1time,
		escortcalltime,
		vo10time,
		toolongtime1,
		vo16time,
		attack2time,intro_shot1overtime,
		vo7Btime,jakspawntime,jakgotime2,rockslideambushtime,vo20time,vo22time,obj7time,
		convoygo1time,cooknotaroundtime,attack3time,vo7Dtime,vo23time,tugpickuppowertime,
		obj8time,
		toolong2time,
		attack4time,intro_shot2overtime,
		vo7Ctime,vo25time,praise1time,praise2time,praise3time,praise4time,
		vo_recydeadtime,rockslidetime,rockslide_shot1_overtime,rockslide_shot2_overtime,
		rockslide_shot3_overtime,vo19time,intro_shot3overtime,
		intro_shot4overtime,pilots_move2time,vo34time,lung_check,
		jak_9_10_spawntime,dropship_landtime,swap_dropshiptime,
		vo35time,doors_opentime,move_into_dropshiptime,dropship_endcintime,
	    move_into_dropshiptime2,move_into_dropshiptime3,
		on_foot_shot1_overtime,amini_gotime,on_foot_shot2_overtime,
		pilo_go2time,on_foot_shot3_overtime,
		too_long_build_lungtime,take_off_soundtime,
		f_last;

	// handles
	Handle
		h_first,
		nav1,nav2,escort1a,escort1b,tug1,player,
		ambush1tanka,ambush1tankb,shab,msg2,msg1,
		attack1tanka,attack1tankb,msg3,msg4,
		attack2tanka,attack2tankb,jak1,jak2,jak3,jak4,jak5,jak6,jak7,jak8,jakstay1,jakstay2,
		routeattacker1,routeattacker1a,routeattacker1b,routeattacker1c,
		routeattacker2a,routeattacker2b,
		routeattacker3a,routeattacker3b,routeattacker3c,msg20,msg22,
		escort2a,escort2b,routeattacker4a,routeattacker4b,
		attack3tanka,attack3tankb,attack4tanka,attack4tankb,
		msg13,msg23,power,msg25,emptygroup,playersrecy,vofail1,landslide,camlook1,camlook2,
		msg24,player_pilo1,shab_pilo,intro_shot2look,kiln,shab_pilo3,
		fvcons1,player_pilo,msg34,jak9,jak10,
		pilots_look1,msg6,lung,CutSc01msg,lands1,lands2,lands3,lands4,
		msg21,dropship,dropship_cam1look,amini,pilo_on_foot,
		suprise_jak1,suprise_jak2,suprise_jak3,
		escort_cin1,escort_cin2,power_cin,tug_cin,coll01,stall,stall2,
		blah1,

		h_last;


	// integers
	int
		i_first,
		a,

		i_last;
};
DLLBase * BuildMission(void)
{
	return new scion01();
}

void scion01::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	missionstart = false;
	rondevous1 = false;
	convoygo1 = false;
	escort1afarahead = false;
	escort1aclose = false;	
	missionwon = false;
	engage_escorts = false;
	ambush1over = false;
	ambushers1killed = false;
	escort1a_look = false;
	escort1b_look = false;
	tug_moveout_nav2 = false;
	vo1 = false;
	vo2 = false;
	vo3 = false;
	playermorphed = false;
	playernotmorphed= false;
	warned1 = false;
	warned2 = false;
	morphdrill = false;
	vo6 = false;
	vo7 = false;
	shabgopatrol = false;
	baseattack1 = false;
	vo8 = false;
	shabdead = false;
	escortcall = false;
	vo10 = false;
	toolong1 = false;
	cooknotaround = false;
	vo16 = false;
	objectifynav1 = false;
	escortsgoinghome = false;
	attack2 = false;
	vo7B = false;
	vo8B = false;
	jaksgo = false;
	jakstop1 = false;
	jakstop2 = false;
	tugkilled = false;
	routeattack1 = false;
	routeattack2 = false;
	rockslide = false;
	rockslideambush = false;
	vo20 = false;
	rockslideambushersdead = false;
	playeronfoot = false;
	obj7 = false;
	vo22 = false;
	rondevous2 = false;
	leave = false;
	convoygo2 = false;
	escort2afarahead = false;
	escort2aclose = false;
	winmission = false;
	obj8 = false;
	obj9 = false;
	kill1 = false;
	kill2 = false;
	playerjumpgun1 = false;
	playeratnav1 = false;
	toolong2 = false;
	failtooktoolong = false;
	attack3 = false;
	vo7C = false;
	vo8C = false;
	attack3 = false;
	attack4 = false;
	vo7D = false;
	vo8D = false; 
	ambush1spawn = false;
	vo23 = false;
	delay2 = false;
	tugpickuppower = false;
	powerkilled = false;
	vo25 = false;
	obj11 = false;
	praise1 = false;
	praise2 = false;
	praise3 = false;
	praise4 = false;
	playersrecy_dead = false;
	vo_recydead = false;
	obj12 = false;
	tug_at_rockslide = false;
	player_at_rockslide = false;
	rockslide_sequence_over = false;
	begin_rockslide_sequence = false;
	rockslide_shot1 = false;
	rdycam1 = false;
	rockslide_shot1_over = false;
	rockslide_shot2 = false;
	rockslide_shot2_over = false;
	rockslide_shot2_settime = false;
	rockslide_shot3 = false;
	rockslide_shot3_over = false;
	rockslide_shot3_settime = false;
	vo19 = false;
	check1 = false;
	cin1over = false;
	intro_shot1over = false;
	intro_rdycam1 = false;
	intro_shot2over = false;
	shot2_settime = false;
	intro_shot3over = false;
	shot3_settime = false;
	intro_shot4over = false;
	shot4_settime = false;
	pilots_move2 = false;
	cons_move1 = false;
	cons_move2 = false;
	shab_relook = false;
	obj13 = false;
	lung_built = false;
	vo34 = false;
	got_lungs = false;
	setvo2time = false;
	camcancelled_vo1 = false;
	obj10 = false;
	vo35 = false;
	checkmsg21done = false;
	playsound1 = false;
	playsound2 = false;
	playsound3 = false;
	playsound4 = false;
	dropship_sequence_over = false;
	land = false;
	swap = false;
	doors_open = false;
	move_into_dropship = false;
	move_into_dropship2 = false;
	move_into_dropship3 = false;
	remove_escort2a = false;
	remove_escort2b = false;
	remove_tug1 = false;
	remove_power = false;
	all_aboard = false;
	dropship_shot1 = false;
	dropship_rdycam1 = false;
	dropship_endcin = false;
	msg6_stop = false;
	swap_rockslide1 = false;
	on_foot_cin_over = false;
	on_foot_shot1 = false;
	setup_on_foot_shot1 = false;
	pilo_go1 = false;
	pilo_stop1 = false;
	on_foot_shot2 = false;
	setup_on_foot_shot2 = false;
	amini_go = false;
	on_foot_shot3 = false;
	pilo_go2 = false;
	suprise_jaks = false;
	too_long_build_lung = false;
	take_off_sound = false;

//  floats
	escort_reaction_time = 999999.9f;
	delay1_time = 999999.9f;
	vo1time = 999999.9f;
	vo2time = 999999.9f;
	vo6time = 999999.9f;
	vo7time = 999999.9f;
	toolongtomorph = 999999.9f;
	toolongtomorph2 = 999999.9f;
	baseattack1time = 999999.9f;
	escortcalltime = 999999.9f;
	vo10time = 999999.9f;
	toolongtime1 = 999999.9f;
	vo16time = 999999.9f;
	attack2time = 999999.9f;
	vo7Btime = 999999.9f;
	jakspawntime = 999999.9f;
	jakgotime2 = 999999.9f;
	rockslideambushtime = 999999.9f;
	vo20time = 999999.9f;
	vo22time = 999999.9f;
	obj8time = 999999.9f;
	obj7time = 999999.9f;
	vo3time = 999999.9f;
	convoygo1time = 999999.9f;
	cooknotaroundtime = 999999.9f;
	toolong2time = 999999.9f;
	attack3time = 999999.9f;
	attack4time = 999999.9f;
	vo7Ctime = 999999.9f;
	vo7Dtime = 999999.9f;
	vo23time = 999999.9f;
	tugpickuppowertime = 999999.9f;
	vo25time = 999999.9f;
	praise1time = 999999.9f;
	praise2time = 999999.9f;
	praise3time = 999999.9f;
	praise4time = 999999.9f;
	vo_recydeadtime = 999999.9f;
	rockslidetime = 999999.9f;
	rockslide_shot1_overtime = 999999.9f;
	rockslide_shot2_overtime = 999999.9f;
	rockslide_shot3_overtime = 999999.9f;
	vo19time = 999999.9f;
	intro_shot1overtime = 999999.9f;
	intro_shot2overtime = 999999.9f;
	intro_shot3overtime = 999999.9f;
	intro_shot4overtime = 999999.9f;
	pilots_move2time = 999999.9f;
	vo34time = 999999.9f;
	lung_check = 999999.9f;
	vo35time = 999999.9f;
	jak_9_10_spawntime = 999999.9f;
	dropship_landtime = 999999.9f;
	swap_dropshiptime = 999999.9f;
	doors_opentime = 999999.9f;
	move_into_dropshiptime = 999999.9f;
	move_into_dropshiptime2 = 999999.9f;
	move_into_dropshiptime3 = 999999.9f;
	dropship_endcintime = 999999.9f;
	on_foot_shot1_overtime = 999999.9f;
	amini_gotime = 999999.9f;
	on_foot_shot2_overtime = 999999.9f;
	pilo_go2time = 999999.9f;
	on_foot_shot3_overtime = 999999.9f;
	too_long_build_lungtime = 999999.9f;
	take_off_soundtime = 999999.9f;
//  handles
	nav1 = NULL;
	nav2 = NULL;
	escort1a = NULL;
	escort1b = NULL;
	tug1 = NULL;
	shab = GetHandle("shab");
	attack1tanka = NULL;
	attack1tanka = NULL;
	player = NULL;
	ambush1tanka = NULL;
	ambush1tankb = NULL;
	msg2 = NULL;
	msg1 = NULL;
	msg3 = NULL;
	msg4 = NULL;
	attack2tanka = NULL;
	attack2tankb = NULL;
	attack3tanka = NULL;
	attack3tankb = NULL;
	attack4tanka = NULL;
	attack4tankb = NULL;
	jak1 = NULL;
	jak2 = NULL;
	jak3 = GetHandle("jak3");
	jak4 = GetHandle("jak4");
	jak5 = GetHandle("jak5");
	jak6 = NULL;
	jak7 = GetHandle("jak7");
	jak8 = GetHandle("jak8");
	jakstay1 = GetHandle("jakstay1");
	jakstay2 = GetHandle("jakstay2");
	routeattacker1 = NULL;
	routeattacker1a = NULL;
	routeattacker1b = NULL;
	routeattacker1c = NULL;
	routeattacker2a = NULL;
	routeattacker2b = NULL;
	routeattacker3a = NULL;
	routeattacker3b = NULL;
	routeattacker3c = NULL;
	routeattacker4a = NULL;
	routeattacker4b = NULL;
	msg20 = NULL;
	msg22 = NULL;
	escort2a = GetHandle("escort2a");
	escort2b = GetHandle("escort2b");
	msg24 = NULL;
	msg23 = NULL;
	msg25 = NULL;
	power = NULL;
	emptygroup = NULL;
	playersrecy = GetHandle("playersrecy");
	vofail1 = NULL;
	landslide = GetHandle("landslide");
	camlook1 = GetHandle("camlook1");
	camlook2 = GetHandle("camlook2");
	player_pilo1 = GetHandle("player_pilo1");
	shab_pilo = GetHandle("shab_pilo");
	intro_shot2look = GetHandle("intro_shot2look");
	kiln = GetHandle("kiln");
	shab_pilo3 = NULL;
	pilots_look1 = GetHandle("pilots_look1");
	fvcons1 = GetHandle("fvcons1");
	player_pilo = GetHandle("player_pilo");
	msg6 = NULL;
	lung = NULL;
	msg34 = NULL;
	CutSc01msg = NULL;
	msg21 = NULL;
	jak9 = NULL;
	jak10 = NULL;
	lands1 = NULL;
	lands2 = NULL;
	lands3 = NULL;
	lands4 = NULL;
	dropship = NULL;
	suprise_jak1 = NULL;
	suprise_jak2 = NULL;
	suprise_jak3 = NULL;
	escort_cin1 = GetHandle("escort_cin1");
	escort_cin2 = GetHandle("escort_cin2");
	tug_cin = GetHandle("tug_cin");
	power_cin = GetHandle("power_cin");

	dropship_cam1look = GetHandle("dropship_cam1look");
	amini = NULL;
	pilo_on_foot = NULL;
	coll01 = GetHandle("coll01");
	stall = NULL;
	stall2 = NULL;
	blah1 = NULL;
//  integers
	a = 0;
	SetTeamColor(5,85,255,85); //Amini (rebel scion)

}

void scion01::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if ((!lung_built) && (IsOdf2(h,"fblung")))
	{
		lung_built = true;  
	}
}

bool scion01::PostLoad(bool missionSave)
{
	bool ret = SPMission::PostLoad(missionSave);

	if (missionSave)
		return ret;

	SetTeamColor(5,85,255,85); //Amini (rebel scion)

	return ret;
}

void scion01::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/
	player = GetPlayerHandle();

	char tempstr[128];

	//INTRO CINERACTIVE.  
	if (!cin1over)
	{
		if (!intro_shot1over)
		{
			if (!intro_rdycam1)
			{
				CameraReady();
				intro_shot1overtime = (GetTime() + 17);
				intro_rdycam1 = true;
			}
			
			CameraPath("shot1_path1",500,1000,shab_pilo);

			//moving constructor for dramatic effect
			if (!cons_move1)
			{
				Goto(fvcons1,"builder_path1",0);
				cons_move1 = true;
			}

			if ((intro_shot1overtime < GetTime()))
			{
				intro_shot1over = true;
			}

		}

		if ((!intro_shot2over) && (intro_shot1over))
		{
			if (!shot2_settime)
			{
				intro_shot2overtime = (GetTime() + 5);
				Retreat(player_pilo1,"player_pilo1_path1");
				Retreat(shab_pilo,"shab_pilo_path1");
				Goto(fvcons1,"builder_path2",0); //moving builder into position
				shot2_settime = true;
			}
			
			CameraPath("intro_shot2path",500,0,intro_shot2look);
			
			if ((intro_shot2overtime < GetTime()))
			{
				RemoveObject(player_pilo1);
				RemoveObject(shab_pilo);
				intro_shot2over = true;
			}
		}

		if ((!intro_shot3over) && (intro_shot2over))
		{
			if (!shot3_settime)
			{
				intro_shot3overtime = (GetTime() + 28);
				CutSc01msg = AudioMessage("cutsc0101.wav"); //"the scions gave me the same gift that they gave Yelena..."
				shot3_settime = true;
			}
			
			CameraPath("intro_shot3path",1500,100,kiln);
			
			if ((intro_shot3overtime < GetTime()))
			{
				player_pilo1 = BuildObject("sspilo",0,"player_pilo1_spawn");
				shab_pilo = BuildObject("sspilo",0,"shab_pilo_spawn");
				LookAt(player_pilo1,pilots_look1);
				LookAt(shab_pilo,pilots_look1);
				pilots_move2time = (GetTime() + 5);
				intro_shot3over = true;
			}
		}

		if ((!intro_shot4over) && (intro_shot3over))
		{
			if (!shot4_settime)
			{
				intro_shot4overtime = (GetTime() + 18);
				shot4_settime = true;
			}
			
			CameraPath("intro_shot4path",200,0,player_pilo1);

			if ((!pilots_move2) && (pilots_move2time < GetTime()))
			{
				Retreat(player_pilo1,"player_path");
				Retreat(shab_pilo,"shab_path");	
				pilots_move2 = true;
			}

			if ((intro_shot4overtime < GetTime()))
			{
				intro_shot4over = true;
				RemoveObject(player_pilo1);
				RemoveObject(shab_pilo);
				shab_pilo3 = BuildObject("sspilo",1,"shab_spawn2");
				SetMaxHealth(shab_pilo3,15000);
				SetCurHealth(shab_pilo3,15000);
				Retreat(shab_pilo3,shab);
				CameraFinish();
			
			//	if (!cons_move2)
			//	{
			//			Goto(fvcons1,"builder_path2",0);
			//		cons_move2 = true;
	    	//	}

				cin1over = true;
			}
		}

		//if the player hits spacebar and cancels the cineractive
		if (CameraCancelled())
		{
			if (IsAround(player_pilo1))
			{
				RemoveObject(player_pilo1);
			}

			if (IsAround(shab_pilo))
			{
				RemoveObject(shab_pilo);
			}

			if (IsAround(shab_pilo3))
			{
				RemoveObject(shab_pilo3);
			}

			if (!cons_move2)
			{
				Goto(fvcons1,"builder_path2",0);
				cons_move2 = true;
			}
			
			if (!IsAudioMessageDone(CutSc01msg))
			{
				StopAudioMessage(CutSc01msg);
			}
			CameraFinish();
			shab_pilo3 = BuildObject("sspilo",1,"shab_spawn2");
			SetMaxHealth(shab_pilo3,15000);
			SetCurHealth(shab_pilo3,15000);
			Retreat(shab_pilo3,shab);
			cin1over = true;
		}
	}
	
	if (cin1over)
	{
		if ((!missionstart) && (!IsAround(shab_pilo3)))
		{
			SetAvoidType(escort2a,0);
			SetAvoidType(escort2b,0);
			Stop(shab);
			LookAt(shab,player);
			SetScrap(1,0);
			SetMaxHealth(shab,10000);
			SetCurHealth(shab,10000);
			SetSkill(shab,3);
			SetObjectiveOn(shab);
			SetObjectiveName(shab,"Shabayev");
			vo1time = (GetTime() + 3);
			Patrol(jak3,"jak_3_4_path");
			Follow(jak4,jak3);
			Patrol(jak5,"jak_5_path");
			Patrol(jak6,"jak_6_path");
			Patrol(jak7,"jak_7_8_path");
			Follow(jak8,jak7);
			Stop(jakstay1);
			Stop(jakstay2);
			jak_9_10_spawntime = (GetTime() + 3);
			Pickup(tug_cin,power_cin);

			missionstart = true;
		}

		//spawning in jak killers
		if (jak_9_10_spawntime < GetTime())
		{
			jak9 = BuildObject("mcjak01",0,"jak9spawn");
			jak10 = BuildObject("mcjak01",0,"jak10spawn");
			Goto(jak9,"jak_go1");
			Goto(jak10,"jak_go1");
			jak_9_10_spawntime = (GetTime() + 300);
		}
		//telling shab to re-look at player if he gets in his tank
		if ((!shab_relook) && (!shabgopatrol) && (!IsAround(player_pilo)))
		{
			LookAt(shab,player);
			shab_relook = true;
		}

		if ((!vo1) && (vo1time < GetTime()))
		{
			msg1 = AudioMessage("scion0101.wav"); //(You're new to your body, I understand...)
			vo1 = true;
		}



		if ((!settime_vo6) && (vo1) && (IsAudioMessageDone(msg1)))
		{
			vo6time = (GetTime() + 2.5f);	
			settime_vo6 = true;
		}

		if ((!vo6) && (vo6time < GetTime()))
		{
			msg6 = AudioMessage("scion0106.wav"); // Shab, Explaining scion power rules, tells player to build a lung on Kiln
			jakspawntime = (GetTime() + 5);
		//	baseattack1time = (GetTime() + 110);  
			vo6 = true;
		}

		if ((!obj13) && (vo6) && (!shabdead) && (IsAudioMessageDone(msg6)))
		{
			ClearObjectives();
			AddObjective("scion0113.otf", WHITE); //build a lung on your kiln
			too_long_build_lungtime = (GetTime() + 90);
			obj13 = true;
		}

		//this will fail the player if he takes too long to build the lung
		if ((!too_long_build_lung) && (!lung_built) && (too_long_build_lungtime < GetTime()))
		{
			ClearObjectives();
			AddObjective("scion0113b.otf", WHITE);	
			AddObjective("scion0113c.otf", RED);
			AudioMessage("scion0136.wav");
			FailMission(GetTime() + 10,"scion01L6.txt"); 
			too_long_build_lung = true;
		}

		//This will stop MSG6 if the player builds the lung early
		if ((!msg6_stop) && (vo6) && (lung_built) && (!IsAudioMessageDone(msg6)))
		{
			StopAudioMessage(msg6);
			msg6_stop = true;
		}

		//checking to see when the lung is built!
/*
		if ((!lung_built) && (lung_check < GetTime()))
		{
			lung_check = GetTime() + 1.0f;

			a = CountUnitsNearObject(0,99999.0f,1,"fblung");

			if (a > 1)
			{
				lung_check = GetTime() + 999999.9f;
				vo2time = (GetTime() + 2);
				lung_built = true;
			}
		}

*/		//Checking when the lung is built
		if ((!setvo2time) && (lung_built) && (obj13) && (!too_long_build_lung))
		{
			vo2time = (GetTime() + 2);
			setvo2time = true;
		}

////Telling player to morph...
		if ((!vo2) && (lung_built) && (vo2time < GetTime()))
		{
			msg2 = AudioMessage("scion0102.wav"); // Good job, now the Kiln is powered.  You should also learn how to morph...
			toolongtomorph = (GetTime() + 40);
			vo2 = true;
		}

		if ((!obj10) && (vo2) && (!shabdead) && (IsAudioMessageDone(msg2)))
		{
			ClearObjectives();
			AddObjective("scion0110.otf", WHITE);	
			obj10 = true;
		}

		///this will stop shab's voice if player morphs his ship early
		if ((!playerjumpgun1) && (!playermorphed) && (vo2) && (!IsAudioMessageDone(msg2) && (IsDeployed(player))))
		{
			StopAudioMessage(msg2);
			vo3time = (GetTime() + 1);
			playermorphed = true;
			playerjumpgun1 = true;
		}
		/////

		if (!morphdrill)
		{
				//player morphs correctly
			if ((!playermorphed) && (!playerjumpgun1) && (vo2) && (IsAudioMessageDone(msg2) && (IsDeployed(player))))
			{
			
				vo3time = (GetTime() + 1);
				morphdrill = true;
				playermorphed = true;
			}
				//player stalls to morph
			if ((!playermorphed) && (!warned1) && (toolongtomorph < GetTime()))
			{
				stall = AudioMessage("scion0104.wav"); // shab, There's no time to waste, John...morph your ship now!
				toolongtomorph2 = (GetTime() + 20);
				warned1 = true;
			}
				//player still hasn't morphed
			if ((!playermorphed) && (!warned2) && (toolongtomorph2 < GetTime()))
			{
				stall2 = AudioMessage("scion0118.wav"); // shab You maybe have been a major in braddock's army, but you are just a student here...
				warned2 = true;
				jakspawntime = (GetTime() + 5);
				vo34time = (GetTime() + 6);
			//	baseattack1time = (GetTime() + 45);
				morphdrill = true;
			}
		}

		if ((!vo3) && (vo3time < GetTime()))
		{
			blah1 = AudioMessage("scion0103.wav"); //shab, Good while morhped your ships can use different weapons and tactics.
			vo34time = (GetTime() + 6);
			vo3 = true;
		}

		if ((!vo34) && (vo34time < GetTime()))
		{
			msg34 = AudioMessage("scion0134.wav");//scion0134.wav SHABAYEV OK JOHN, LETS GET READY FOR THE ESCORT.  UPGRADE THE KILN INTO A FORGE AND BEGIN BUILDING SOME WARRIORS AND SENTRY'S.
			baseattack1time = (GetTime() + 45);
			vo34 = true;
		}

		//sending shab to patrol
		if ((!shabgopatrol) && (vo34) && (!shabdead) && (IsAudioMessageDone(msg34)))
		{
			Patrol(shab,"shab_patrol");
			ClearObjectives();
			AddObjective("scion0101.otf", WHITE); //upgrade forge, build warriors and sentries.
			shabgopatrol = true;
		}


	//////controlling the Jak creatures....
		if ((!jaksgo) && (jakspawntime < GetTime()))
		{
			jak1 = BuildObject("mcjak01",0,"jak1spawn");
			jak2 = BuildObject("mcjak01",0,"jak2spawn");
			Goto(jak1,"jakstop1");
			Follow(jak2,jak1);
			jaksgo = true;
		}

		if ((!jakstop1) && (IsAlive(jak1) && (GetDistance(jak1,"jakstop1") < 15)))
		{
			if (IsAlive(jak1))
			{
				Stop(jak1);
				LookAt(jak1,playersrecy);		
			}
			if (IsAlive(jak2))
			{
				Stop(jak2);
				LookAt(jak2,playersrecy);		
			}		

			jakgotime2 = (GetTime() + 10);
			jakstop1 = true;
		}

		if ((!jakstop2) && (jakgotime2 < GetTime()))
		{
			if (IsAlive(jak1))
			{
				Goto(jak1,"jakstop2");
			}
			if ((IsAlive(jak2) && (IsAlive(jak1))))
			{
				Follow(jak2,jak1);
			}

			jakstop2 = true;
		}
	/////

	///WAVES
		//WAVE1
		if ((!baseattack1) && (baseattack1time < GetTime()))
		{
			attack1tanka = BuildObject("ivscout",2,"attack1a");
			attack1tankb = BuildObject("ivscout",2,"attack1b");
			SetSkill(attack1tanka,1);
			SetSkill(attack1tankb,1); 
			Attack(shab,attack1tanka);
			Attack(attack1tankb,player);
			vo7time = (GetTime() + 2);

			//setting times for the rest of the spawns
			attack2time = (GetTime() + 100); //100
			attack3time = (GetTime() + 220); //220
			attack4time = (GetTime() + 350); //350
			escortcalltime = (GetTime() + 500); //500
			baseattack1 = true;
		}

		if ((!vo7) && (vo7time < GetTime()))
		{
			AudioMessage("scion0107.wav"); // Give me a hand, i'm under fire
			vo7 = true;
		}

		if ((!vo8) && (vo7) && (IsAlive(shab) && (!IsAlive(attack1tanka) && (!IsAlive(attack1tankb)))))
		{
			praise1time = (GetTime() + 1.3f);
			Patrol(shab,"shab_patrol");
 
			vo8 = true;
		}

		if ((!praise1) && (praise1time < GetTime()))
		{		
			AudioMessage("scion0108.wav");// Good job (shab)
			praise1 = true;
		}

		///WAVE2
		if ((!attack2) && (attack2time < GetTime()))
		{
			attack2tanka = BuildObject("ivscout",2,"attack2a");
			attack2tankb = BuildObject("ivscout",2,"attack2b");
			SetSkill(attack2tanka,1);
			SetSkill(attack2tankb,1); 
			Attack(shab,attack2tanka);
			Attack(attack2tankb,player);
			vo7Btime = (GetTime() + 3);
			attack2 = true;
		}

		if ((!vo7B) && (vo7Btime < GetTime()))
		{
		//	AudioMessage("scion0107.wav"); // Hostiles!  John give me a hand! (shab)
			vo7B = true;
		}

		if ((!vo8B) && (vo7B) && (IsAlive(shab) && (!IsAlive(attack2tanka) && (!IsAlive(attack2tankb)))))
		{
			praise2time = (GetTime() + 1.3f);
			Patrol(shab,"shab_patrol");

			vo8B = true;
		}

		if ((!praise2) && (praise2time < GetTime()))
		{		
		//	AudioMessage("scion0108.wav");// Good job (shab)
			praise2 = true;
		}


		
		//WAVE3

		if ((!attack3) && (attack3time < GetTime()))
		{
			attack3tanka = BuildObject("ivscout",2,"attack1a");
			attack3tankb = BuildObject("ivtank",2,"attack1b");
			SetSkill(attack3tanka,1);
			SetSkill(attack3tankb,1); 
			Attack(shab,attack3tanka);
			Attack(attack3tankb,player);
			vo7Ctime = (GetTime() + 3);
			attack3 = true;
		}

		if ((!vo7C) && (vo7Ctime < GetTime()))
		{
		//	AudioMessage("scion0107.wav"); // Hostiles!  John give me a hand! (shab)
			vo7C = true;
		}

		if ((!vo8C) && (vo7C) && (IsAlive(shab) && (!IsAlive(attack3tanka) && (!IsAlive(attack3tankb)))))
		{
			praise3time = (GetTime() + 1.3f);
			Patrol(shab,"shab_patrol");

			vo8C = true;
		}

		if ((!praise3) && (praise3time < GetTime()))
		{		
		//	AudioMessage("scion0108.wav");// Good job (shab)
			praise3 = true;
		}

		//WAVE4

		if ((!attack4) && (attack4time < GetTime()))
		{
			attack4tanka = BuildObject("ivscout",2,"attack2a");
			attack4tankb = BuildObject("ivtank",2,"attack2b");
			SetSkill(attack4tanka,1);
			SetSkill(attack4tankb,1); 
			Attack(shab,attack4tanka);
			Attack(attack4tankb,player);
			vo7Dtime = (GetTime() + 3);
			attack4 = true;
		}

		if ((!vo7D) && (vo7Dtime < GetTime()))
		{
		//	AudioMessage("scion0107.wav"); // Hostiles!  John give me a hand! (shab)
			vo7D = true;
		}

		if ((!vo8D) && (vo7D) && (IsAlive(shab) && (!IsAlive(attack4tanka) && (!IsAlive(attack4tankb)))))
		{
			praise4time = (GetTime() + 1.3f);
			Patrol(shab,"shab_patrol");
			vo8D = true;
		}

		if ((!praise4) && (praise4time < GetTime()))
		{		
		//	AudioMessage("scion0108.wav");// Good job (shab)
			praise4 = true;
		}


	//CALL FROM DELTA WING
		if ((!escortcall) && (escortcalltime < GetTime()))
		{
			AudioMessage("scion0109.wav");// Delta wing--We have the power source, ETA to rondevous is 3 minutes.
			escort1a = BuildObject("fvscout",1,"escort1a");
			escort1b = BuildObject("fvscout",1,"escort1b");
			tug1 = BuildObject("fvtug",1,"tug1");
			power = BuildObject("cotran01",0,"power");
			Stop(escort1a);
			Stop(escort1b);
			Stop(tug1);
			SetMaxHealth(tug1,5000);
			SetCurHealth(tug1,5000);
			SetAvoidType(escort1a,0);
			SetAvoidType(escort1b,0);
			SetAvoidType(escort2a,0);
			SetAvoidType(escort2b,0);
			SetAvoidType(tug1,0);
			tugpickuppowertime = (GetTime() + 3);
			vo10time = (GetTime() + 3);
			convoygo1time = (GetTime() + 8);
			escortcall = true;
		}

		if ((!tugpickuppower) && (tugpickuppowertime < GetTime()))
		{
			Pickup(tug1,power);
			tugpickuppower = true;
		}

		if ((!vo10) && (vo10time < GetTime()))
		{
			msg3 = AudioMessage("scion0110.wav"); // shab: Excellent, Delta wing.  Cook you're up.  Take a couple wingmen, and meet them at Nav 1.  Leave a few ships to help me defend the base. (SHAB)
			vo10 = true;
		}
		
		if ((!objectifynav1) && (vo10) && (!shabdead) && (IsAudioMessageDone(msg3)))
		{
			nav1 = BuildObject("ibnav",1,"nav1");			
			SetObjectiveOn(nav1);
			TranslateString2(tempstr, sizeof(tempstr), "MissionS0101");  // Nav 1
			SetObjectiveName(nav1,tempstr);
			SetObjectiveOff(shab);
			ClearObjectives();
			AddObjective("scion0102.otf", WHITE);
			objectifynav1 = true;
		}

		if (!rondevous1)
		{
			if ((!convoygo1) && (convoygo1time < GetTime()))
			{
				Retreat(escort1a,"rondevous1");
				Retreat(tug1,"rondevous1");
				Follow(escort1b,tug1);
				cooknotaroundtime = (GetTime() + 100);
				convoygo1 = true;
			}
			
			if ((!escort1afarahead) && (GetDistance(escort1a,tug1) > 100))
			{
				Stop(escort1a);
				LookAt(escort1a,tug1);
				escort1aclose = false;
				escort1afarahead = true;
			}

			if ((!escort1aclose) && (escort1afarahead) && (GetDistance(escort1a,tug1) < 99))
			{
				Retreat(escort1a,"rondevous1");
				escort1aclose = true;
				escort1afarahead = false;
			}

			if ((GetDistance(tug1,"rondevous1") < 125 && (GetDistance(tug1,player) < 125)))
			{
				msg13 = AudioMessage("scion0113.wav"); //Delta wing here, we have Cook on radar. Lt. Shabayev, are you sure we can trust this man with the power source?   
				Stop(escort1a);
				SetObjectiveOff(nav1);
				rondevous1 = true;
			}
		}

		if ((!delay2) && (rondevous1) && (IsAudioMessageDone(msg13)))
		{
			vo23time = (GetTime() +1);
			delay2 = true;
		}

		if ((!vo23) && (vo23time < GetTime()))
		{
			msg23=AudioMessage("scion0123.wav");  //SCION0123 SHAB - you have my word on it
			vo23 = true;
		}

		//ambush when player first meets tug
		if ((!ambush1spawn) && (vo23) && (IsAudioMessageDone(msg23)))
		{
			ambush1tanka = BuildObject("ivtank",2,"ambush1a");
			ambush1tankb = BuildObject("ivscout",2,"ambush1b");
			SetSkill(ambush1tanka,2);
			SetSkill(ambush1tankb,1);
			Attack(ambush1tanka,tug1);
			Attack(ambush1tankb,player);
			escort_reaction_time = (GetTime() + 2);	
			ambush1spawn = true;
		}

	//seeing when player is at nav1
		if ((!playeratnav1) && (vo10) && (GetDistance(player,"nav1") < 100))
		{
			playeratnav1 = true;
		}
		///

		///if cook is not there in 100 sec
		if ((!cooknotaround) && (!rondevous1) && (cooknotaroundtime < GetTime()))
		{
			AudioMessage("scion0112.wav"); // Delta wing here, we are at Nav 1 but Cook is not around!
			toolongtime1 = (GetTime() + 30);
			cooknotaround = true;
		}
		///still not there
		if ((!toolong1) && (!rondevous1) && (toolongtime1 < GetTime()))
		{
			AudioMessage("scion0111.wav");	//shab:  Hurry up Cook!  They could run into trouble out there.
			toolong2time = (GetTime() + 180);
			toolong1 = true;
		}
		//if player takes too long in getting to Nav 1 the mission is failed...
		if ((!toolong2) && (!rondevous1) && (toolong2time < GetTime()))
		{
			msg24 = AudioMessage("scion0124.wav"); //SCION0124  That's it John, I have to let you go!  If you cannot follow orders...
			toolong2 = true;
		}

		if ((!failtooktoolong) && (toolong2) && (IsAudioMessageDone(msg24)))
		{
			ClearObjectives();
			AddObjective("scion0111.otf", WHITE); //mission failed
			FailMission(GetTime() + 6,"scion01L1.txt");
			failtooktoolong = true;
		}
		//////


	///After the rendezvous...
		if ((!engage_escorts) && (escort_reaction_time < GetTime()))
		{
			SetObjectiveOff(nav1);
			Attack(escort1a,ambush1tanka);
			Attack(escort1b,ambush1tankb);
			AudioMessage("scion0114.wav");  //Delta wing: What the..?!  Ambush!  Protect the tug! 
			engage_escorts = true;
		}

		if (!ambush1over)
		{
			if ((!ambushers1killed) && (ambush1spawn) && (!IsAlive(ambush1tanka) && (!IsAlive(ambush1tankb))))
			{
				if (IsAlive(escort1a))
				{
					Retreat(escort1a, "escort1a_go1");
				}
				if (IsAlive(escort1b))
				{
					Retreat(escort1b, "escort1b_go1");
				}

				ambushers1killed = true;
				delay1_time = GetTime() + 5;
			}

			if ((!escort1a_look) && (IsAlive(escort1a) && (ambushers1killed) && (GetDistance(escort1a,"escort1a_go1") < 20)))
			{
				LookAt(escort1a,player);
				escort1a_look = true;
			}

			if ((!escort1b_look) && (IsAlive(escort1b) && (ambushers1killed) && (GetDistance(escort1b,"escort1b_go1") < 20)))
			{
				LookAt(escort1b,player);
				escort1b_look = true;
			}	

		}
		//////////////***************************
		//////////////***************************
		if ((!escortsgoinghome) && (delay1_time < GetTime()))
		{
			AudioMessage("scion0115.wav");// Delta wing:  We are handing the tug over to cook and heading to base
			vo16time = (GetTime() + 15);
			Retreat(escort1a,"escort1a_go2");
			Retreat(escort1b,"escort1b_go2"); 
			routeattacker1 = BuildObject("ivscout",2,"routeattack1a");
			routeattacker1b = BuildObject("ivscout",2,"routeattack1b");
			routeattacker1c = BuildObject("ivscout",2,"routeattack1c");
			routeattacker2a = BuildObject("ivscout",2,"routeattack2a");
			routeattacker2b = BuildObject("ivtank",2,"routeattack2b");
			SetSkill(routeattacker1,2);
			SetSkill(routeattacker1b,1);
			SetSkill(routeattacker1c,1);
			SetSkill(routeattacker2a,2);
			SetSkill(routeattacker2b,1); 
			escortsgoinghome = true;
		}

		if ((!vo16) && (vo16time < GetTime()))
		{
			msg4 = AudioMessage("scion0116.wav"); //shab - Ok Cook, escort the tug to nav 2 where another wing will relieve you.  
			nav2 = BuildObject("ibnav",1,"nav2");			
			SetObjectiveOn(nav2);
			TranslateString2(tempstr, sizeof(tempstr), "MissionS0102");  // Nav 2
			SetObjectiveName(nav2,tempstr);
			vo16 = true;
		}

		if ((!tug_moveout_nav2) && (vo16) && (IsAudioMessageDone(msg4)))
		{
			Retreat(tug1,"tug_path1");
			SetObjectiveOn(tug1);
			TranslateString2(tempstr, sizeof(tempstr), "MissionS0103");  // Hauler
			SetObjectiveName(tug1,tempstr);
			ClearObjectives();
			AddObjective("scion0103.otf", WHITE); //escort tug to nav 2
			tug_moveout_nav2 = true;
		}

		if ((!routeattack1) && (GetDistance(tug1,"trig_routeattack1") < 30))
		{
			Attack(routeattacker1,player);
			Attack(routeattacker1b,tug1);
			Attack(routeattacker1c,tug1);
			routeattack1 = true;

		}

		if ((!routeattack1) && (GetDistance(player,"trig_routeattack1") < 100))
		{

			Attack(routeattacker1,player);
			Attack(routeattacker1b,tug1);
			Attack(routeattacker1c,tug1);
			routeattack1 = true;

		}

		if ((!routeattack2) && (GetDistance(tug1,"trig_routeattack2") < 30))
		{
	   		SetSkill(routeattacker2a,1);
			Attack(routeattacker2a,tug1);
			routeattack2 = true;
		}

		//checking to see when tug is at rockslide
		if ((!tug_at_rockslide) && (tug_moveout_nav2) && (IsAround(tug1) && (GetDistance(tug1,"trig_rockslide") < 40)))
		{
			check1 = true;
			tug_at_rockslide = true;
		}

		//checking to see when player is at rockslide
		if ((!player_at_rockslide) && (tug_moveout_nav2) && (IsAround(tug1) && (GetDistance(player,"trig_rockslide") < 60)))
		{
			check1 = true;
			player_at_rockslide = true;
		}

		/////////////////
		//**ROCKSLIDE**//
		/////////////////
		if ((!rockslide_sequence_over) && (check1))
		{	//When player or tug reach the rockslide
			if ((!begin_rockslide_sequence) && (check1))
			{	//swapping the landslide with no collision with the one with collision (meslid1a for meslid2a)
				//and the secondary coll box as well
				Matrix pos_land1;
				GetPosition(landslide,pos_land1);
				RemoveObject(landslide);
				landslide = BuildObject("meslida2",0,pos_land1);
				//
				Matrix pos_coll01;
				GetPosition(coll01,pos_coll01);
				RemoveObject(coll01);
				coll01 = BuildObject("mecoll02",0,pos_coll01);
				//
				rockslidetime = (GetTime() + 2);
				begin_rockslide_sequence = true;	
			}

			if ((!rockslide) && (rockslidetime < GetTime()))
			{
				SetAnimation(landslide,"landslide",1);
				StartEarthQuake(10);
				rockslide = true;
			}


			if ((!rockslide_shot1) && (begin_rockslide_sequence))
			{
				if (!rdycam1)
				{
					CameraReady();
					rockslide_shot1_overtime = (GetTime() + 4);
					rdycam1 = true;
				}
	
				CameraPath("campath1",2500,0,camlook1);
			}

			if ((!rockslide_shot1_over) && (rockslide_shot1_overtime < GetTime()))
			{
				rockslide_shot1 = true;
				rockslide_shot1_over = true;
			}

			if ((!rockslide_shot2) && (rockslide_shot1_over))
			{
				if (!rockslide_shot2_settime)
				{
					rockslide_shot2_overtime = (GetTime() + 3);
					rockslide_shot2_settime = true;
				}
				CameraPath("campath2",1500,0,camlook2);		
			}

			if ((!rockslide_shot2_over) && (rockslide_shot2_overtime < GetTime()))
			{
				rockslide_shot2 = true;
				rockslide_shot2_over = true;
			}

			if ((!rockslide_shot3) && (rockslide_shot2_over))
			{
				if (!rockslide_shot3_settime)
				{
					rockslide_shot3_overtime = (GetTime() + 4);
					rockslide_shot3_settime = true;
				}
				CameraPath("campath1",2500,0,camlook1);		
			}

			if ((!rockslide_shot3_over) && (rockslide_shot3_overtime < GetTime()))
			{
				CameraFinish();
				StopEarthQuake();
				vo19time = (GetTime() +1);
				rockslide_shot3 = true;
				rockslide_shot3_over = true;
			}

			if ((!vo19) && (vo19time < GetTime()))
			{
				AudioMessage("scion0119.wav"); //Hauler here, our path has been blocked by a landslide!  Looks like an ambush! 	
				rockslideambushtime = (GetTime() + 7);		//("What was that!?  We just lost the route!  A landslide-")
				rockslide_sequence_over = true;
				vo19 = true;		
			}

		}

		//after rockslide, ambushers attack
		if ((!rockslideambush) && (rockslideambushtime < GetTime()))
		{
			AudioMessage("scion0129.wav"); // Ambush!  Ambush!  Protect the hauler!

			routeattacker3a = BuildObject("ivscout",2,"routeattack3a");	
			SetSkill(routeattacker3a,1);
			Goto(routeattacker3a,player);	

			routeattacker3b = BuildObject("ivscout",2,"routeattack3b");	
			SetSkill(routeattacker3b,1);
			Goto(routeattacker3b,tug1);	

			routeattacker3c = BuildObject("ivtank",2,"routeattack3c");	
			SetSkill(routeattacker3c,1);
			Goto(routeattacker3c,player);
			
			SetObjectiveOff(nav2);
			rockslideambush = true;
		}
	//when rockslide ambushers are dead
		if ((!rockslideambushersdead) && (rockslideambush) && (!IsAlive(routeattacker3a) &&
		   (!IsAlive(routeattacker3b) && (!IsAlive(routeattacker3c)))))
		{
			vo20time = (GetTime() + 8);
			rockslideambushersdead = true;
		}

		if ((!vo20) && (vo20time < GetTime()))
		{
			msg20 = AudioMessage("scion0120.wav");	//Hmm, our geologic data of the planet indicates that the surface should be perfectly stable in that area.  Cook, something is not right here.  I want you to hop out of your tank and take a close look and the landslide area. 
			vo20 = true;
		}

		if ((!obj9) && (vo20) && (IsAudioMessageDone(msg20)))
		{
			ClearObjectives();
			AddObjective("scion0109.otf", WHITE);  //Investigate the landslide area on foot.
			obj9 = true;
		}
	//when player jumps out of tank, and is near the rockslide area, CINERACTIVE trigger
		if ((!playeronfoot) && (vo20) && (IsOdf(player,"fsuser") && 
		   (GetDistance(player,landslide) < 125)))
		{
			//swapping landslide with collision for a one without so the little pilot can get through (meslidea2 for meslidea3)
			Matrix pos_land2;
			GetPosition(landslide,pos_land2);
			RemoveObject(landslide);
			landslide = BuildObject("meslida3",0,pos_land2);
			//

			//stoping shabs voice telling player to investigate landslide on foot if player jumps out of tank b4 she is finished
			if ((vo20) && (!IsAudioMessageDone(msg20)))
			{
				StopAudioMessage(msg20);
			}
			playeronfoot = true;
		}

	/////////////////////////////////////
	//****START ON_FOOT CINERACTIVE****//
	/////////////////////////////////////
		if ((!on_foot_cin_over) && (playeronfoot))
		{
			if (!on_foot_shot1)
			{
				if (!setup_on_foot_shot1)
				{
					pilo_on_foot = BuildObject("fspilo",0,"pilo_on_foot_spawn");
					amini = BuildObject("fvsent",5,"amini_spawn");
					SetIndependence(amini,0);
					CameraReady();
					setup_on_foot_shot1 = true;
				}

				if ((!pilo_go1) && (setup_on_foot_shot1))
				{
					Retreat(pilo_on_foot,"pilo_on_foot_path1");
					pilo_go1 = true;
				}

			//	CameraPath("on_foot_campath1",200,0,pilo_on_foot);
				CameraObject(pilo_on_foot,0,-1,-3,pilo_on_foot);

				if ((!pilo_stop1) && (pilo_go1) && (GetDistance(pilo_on_foot,"pilo_on_foot_endpath1") < 5))
				{
					Stop(pilo_on_foot);
					LookAt(pilo_on_foot,amini);
					amini_gotime = (GetTime() + 5);
					pilo_stop1 = true;
					on_foot_shot1 = true;
				}
			}

			if ((!on_foot_shot2) && (on_foot_shot1))
			{
				CameraPath("behind_pilo",10,0,amini);

				if ((!amini_go) && (amini_gotime < GetTime()))
				{
					on_foot_shot2_overtime = (GetTime() + 11);
					Retreat(amini,"amini_path1");
					AudioMessage("cutsc0206.wav"); //cooke = it looks like a scion ship, but those marking....they aren't from The Collective
					amini_go = true;
				}

				if (on_foot_shot2_overtime < GetTime())
				{
					pilo_go2time = (GetTime() + 1);
					on_foot_shot2 = true;
				}
			}

			if ((!on_foot_shot3) && (on_foot_shot2))
			{
				CameraPath("on_foot_campath1",200,0,pilo_on_foot);

				if ((!pilo_go2) && (pilo_go2time < GetTime()))
				{
					on_foot_shot3_overtime = (GetTime() + 6);
					Retreat(pilo_on_foot,"pilo_on_foot_path2");
					pilo_go2 = true;
				}

				if ((on_foot_shot3_overtime < GetTime()))
				{
					RemoveObject(pilo_on_foot);
					RemoveObject(amini);
					vo22time = (GetTime() + 5);

					//swapping landslide without collision, puttin in collision one
					Matrix pos_land3;
					GetPosition(landslide,pos_land3);
					RemoveObject(landslide);
					landslide = BuildObject("meslida4",0,pos_land3);
					//

					CameraFinish();
					on_foot_shot3 = true;
					on_foot_cin_over = true;
				}
			}
		}

		if ((!vo22) && (vo22time < (GetTime())))
		{
			msg22 = AudioMessage("scion0122.wav");	// i don't know who that was...lets just say i don't think that landslide was a "natural phenomenon".
			obj7time = (GetTime() + 6);
			vo22 = true;
		}

		if ((!obj7) && (vo22) && (IsAudioMessageDone(msg22)))
		{
			SetObjectiveOn(nav2);
			TranslateString2(tempstr, sizeof(tempstr), "MissionS0102");  // Nav 2
			SetObjectiveName(nav2,tempstr);
			Stop(tug1,0); 
			emptygroup = GetFirstEmptyGroup();
			SetGroup(tug1,emptygroup);
			SetObjectiveOff(tug1);
			ClearObjectives();
			AddObjective("scion0107.otf", WHITE);//find an alt route for the hauler
			routeattacker4a = BuildObject("ivscout",2,"routeattack4a");
			routeattacker4b = BuildObject("ivatank",2,"routeattack4b");
			SetSkill(routeattacker4a,0);
			SetSkill(routeattacker4b,1);
			LookAt(routeattacker4a,player);
			LookAt(routeattacker4b,player);
			obj7 = true;
		}

		if ((!kill1) && (obj7) && (GetDistance(player,routeattacker4a) < 150))
		{
			Attack(routeattacker4a,player);
			kill1 = true;
		}

		if ((!kill2) && (obj7) && (GetDistance(player,routeattacker4b) < 150))
		{
			Attack(routeattacker4b,player);
			kill2 = true;
		}
		

		//When the tug reaches the rendezvous point, dropship comes down and picks it up
		if ((!rondevous2) && (obj7) && (GetDistance(tug1,"nav2") < 75)) 
		{															   
			msg21 = AudioMessage("scion0121.wav"); // Epsilon wing reporting, we have visual on the Hauler and are takin it from here 
			SetObjectiveOff(nav2);
			dropship_landtime = (GetTime() + 3);
			Retreat(tug_cin,"tug_end_path",1); //getting tug positioned to go inside drop ship
			rondevous2 = true;
		}

		if ((!checkmsg21done) && (rondevous2) && (IsAudioMessageDone(msg21)))
		{
			vo35time = (GetTime() + 2);
			checkmsg21done = true;
		}

		if ((!vo35) && (vo35time < GetTime()))
		{
			AudioMessage("scion0135.wav"); //excellent work, john, i knew you could do it
			vo35 = true;
		}

		//controlling the dropship that picks up the tug
		if ((!dropship_sequence_over) && (rondevous2))
		{	//telling ship to land
			if ((!land) && (dropship_landtime < GetTime()))
			{
				dropship = BuildObject("fvdrop_land",1,"dropship");	
				SetAnimation(dropship,"land",1);
				swap_dropshiptime = (GetTime() + 15);
				land = true;
			}
			//swapping ships
			if ((!swap) && (swap_dropshiptime < GetTime()))
			{
				RemoveObject(dropship);
				dropship = BuildObject("fvdrop",1,"dropship");	
				doors_opentime = (GetTime() + 1);
				swap = true;		
			}
			//opening doors
			if ((!doors_open) && (doors_opentime < GetTime()))
			{
				SetAnimation(dropship,"deploy",1);	
				move_into_dropshiptime = (GetTime() + 4);
				doors_open = true;
			}
			//moving units into dropship
			if ((!move_into_dropship) && (move_into_dropshiptime < GetTime()))
			{
				Retreat(escort_cin1,"dropship");
				move_into_dropshiptime2 = (GetTime() + 2);
				move_into_dropship = true;
			}

			if ((!move_into_dropship2) && (move_into_dropshiptime2 < GetTime()))
			{
				Retreat(escort_cin2,"dropship");
				move_into_dropshiptime3 = (GetTime() + 2);
				move_into_dropship2 = true;
			}

			if ((!move_into_dropship3) && (move_into_dropshiptime3 < GetTime()))
			{
				Retreat(tug_cin,"dropship");
				move_into_dropship3 = true;
			}
			//removing units once they enter dropship
			if ((!remove_escort2a) && (move_into_dropship2) && (GetDistance(escort_cin1,"dropship") < 5))
			{
				RemoveObject(escort_cin1);
				remove_escort2a = true;
			}
	
			if ((!remove_escort2b) && (move_into_dropship) && (GetDistance(escort_cin2,"dropship") < 5))
			{
				RemoveObject(escort_cin2);
				remove_escort2b = true;			
			}
		
			if ((!remove_tug1) && (move_into_dropship3) && (GetDistance(tug_cin,"dropship") < 5))
			{
				RemoveObject(tug_cin);
				RemoveObject(power_cin);  
				remove_tug1 = true;			
			}		

			//dropship taking off
			if ((!all_aboard) && (remove_escort2a) && (remove_escort2b) && (remove_tug1))
			{
				SetAnimation(dropship,"takeoff",1);	
				dropship_endcintime = (GetTime() + 12);//this will end the CIN and the mission
				SucceedMission(GetTime() + 12,"scion01w1.txt");
				take_off_soundtime = (GetTime() + 4);
				all_aboard = true;
			}	

			//play dropship taking off sound
			if ((!take_off_sound) && (take_off_soundtime < GetTime()))
			{
				AudioMessage("droptoff.wav");
				take_off_sound = true;
			}
			
			//camera controls
			if ((!dropship_shot1) && (rondevous2))
			{
				if (!dropship_rdycam1)
				{
					CameraReady();
					dropship_rdycam1 = true;
				}

				CameraPath("dropship_cam1",5000,0,dropship_cam1look);

				if ((!dropship_endcin) && (dropship_endcintime < GetTime()))
				{
					CameraFinish();
					dropship_sequence_over = true;
					dropship_endcin = true;
					dropship_shot1 = true;
				}			
			}
		}

	/*	if (rondevous2)
		{
			if (!convoygo2)
			{
				Retreat(escort2a,"leave");
				Follow(tug1,escort2a);
				Follow(escort2b,tug1);
				convoygo2 = true;
			}
			
			if (!winmission)
			{
				SucceedMission(GetTime() + 30);
				obj8time = (GetTime() + 8);
				winmission = true;
			}
		}
		
		if ((!obj8) && (obj8time < GetTime()))
		{
			ClearObjectives();
			AddObjective("scion0108.otf", WHITE);
			obj8 = true;
		}*/

//This is spawning in some jaks near the ruins if player gets out of his tank near the ruins
	if ((!suprise_jaks) && (IsOdf(player,"fsuser") && (GetDistance(player,"suprise_jak1") < 150)))
	{
		suprise_jak1 = BuildObject("mcjak01",0,"suprise_jak1");	
		suprise_jak2 = BuildObject("mcjak01",0,"suprise_jak2");	
		suprise_jak3 = BuildObject("mcjak01",0,"suprise_jak3");	
		Attack(suprise_jak1,player);
		Attack(suprise_jak2,player);
		Attack(suprise_jak3,player);
		suprise_jaks = true;
	}

	//***MISSION FAIL CONDITIONS***////

	// If Shabayev ever dies, mission is lost
		if ((!shabdead) && (vo1) && (!IsAlive(shab)))
		{
			FailMission(GetTime() + 15,"scion01L2.txt");
			ClearObjectives();
			AddObjective("scion0105.otf", WHITE);
	
	//this will stop shab from talking if she is every killed while talking
		if ((vo1) && (!IsAudioMessageDone(msg1)))
		{
			StopAudioMessage(msg1);
		}

		if ((vo6) && (!IsAudioMessageDone(msg6)))
		{
			StopAudioMessage(msg6);
		}

		if ((vo2) && (!IsAudioMessageDone(msg2)))
		{
			StopAudioMessage(msg2);
		}

		if ((warned1) && (!IsAudioMessageDone(stall)))
		{
			StopAudioMessage(stall);
		}

		if ((warned2) && (!IsAudioMessageDone(stall2)))
		{
			StopAudioMessage(stall2);
		}

		if ((vo3) && (!IsAudioMessageDone(blah1)))
		{
			StopAudioMessage(blah1);
		}

		if ((vo34) && (!IsAudioMessageDone(msg34)))
		{
			StopAudioMessage(msg34);
		}

		if ((vo10) && (!IsAudioMessageDone(msg3)))
		{
			StopAudioMessage(msg3);
		}
			vo1 = true;
			vo6 = true;
			vo2 = true;
			warned1 = true;
			warned2 = true;
			vo3 = true;
			vo34 = true;
			vo10 = true;


			shabdead = true;
		}
		
	//if tug is ever destroyed, mission failed
		if ((!tugkilled) && (tugpickuppower) && (!rondevous2) && (!IsAround(tug1)))
		{
			FailMission(GetTime() + 15,"scion01L3.txt");
			AudioMessage("scion0117.wav");// Dammit Cooke, you let the tug get destroyed!
			ClearObjectives();
			AddObjective("scion0104.otf", WHITE);
			tugkilled = true;
		}

	//if the powersource is killed, mission failed
		if ((!powerkilled) && (tugpickuppower) && (!rondevous2) && (!IsAround(power)))
		{		
			vo25time = (GetTime() + 3);
			powerkilled = true;
		}

		if ((!vo25) && (vo25time < GetTime()))
		{
			msg25 = AudioMessage("scion0125.wav"); // Dammit Cooke, you let the power get destroyed
			vo25 = true;
		}

		if ((!obj11) && (vo25) && (IsAudioMessageDone(msg25)))
		{
			ClearObjectives();
			AddObjective("scion0111.otf", WHITE);	
			FailMission(GetTime() + 5,"scion01L4.txt");
			obj11 = true;
		}

		//if the player's recycler is ever destroyed--MISSION FAILED
		if ((!playersrecy_dead) && (!IsAround(playersrecy)))
		{
			vo_recydeadtime = (GetTime() + 3);
			playersrecy_dead = true;
		}

		if ((!vo_recydead) && (vo_recydeadtime < GetTime()))
		{
			vofail1 = AudioMessage("scion0131.wav");//Dammit cooke, the recycler has been destroyed
			vo_recydead = true;
		}

		if ((!obj12) && (vo_recydead) && (IsAudioMessageDone(vofail1)))
		{
			ClearObjectives();
			AddObjective("scion0112.otf", WHITE);
			FailMission(GetTime() + 6,"scion01L5.txt");
			obj12 = true;
		}
	}
}




