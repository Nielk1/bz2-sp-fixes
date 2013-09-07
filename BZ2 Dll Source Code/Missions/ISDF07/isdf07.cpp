#include "..\Shared\SPMission.h"

/*
	isdf07Mission

	Just add water!!
*/


class isdf07Mission : public SPMission {
public:
	isdf07Mission(void)
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
	~isdf07Mission()
	{
	}

	void Update(void);

	void AddObject(Handle h);

	void ProcessCommand(unsigned long crc);

private:
	void Setup(void);
	void Execute(void);
	void handlePlayerMistakes();
	void SendEnemies(int type, Handle target);
	void playEndCin();
	void CommandShab();

	// bools
	bool
		b_first,
		startDone, recyDeployed, scavBuilt, powerBuilt,wallsBuilt, BeginCin, BeginSeq,
		ruinsDiscovered, creaturesAttack, shabOutOfVehicle, relicFound,
		shabHurt, troopsAttacked, constBuilt, gunTowBuilt, getNewOrder, shabHasOrder,
		playerOnFoot, justHoped, winMission,
		enemy1deployed,enemy2deployed,enemy3deployed, moviePlaying,
		ship_blown_up,
		relayBuilt,shab_dead,
		b_last;

	// floats
	float
		f_first,
		time,
		next_unit,reminderTimer, timeToFail, errorRemTime1, errorRemTime2, 
		BugFix,
		f_last;

	// handles
	Handle
		h_first,
		foe, spawn1, spawn2, spawn3, animal1, ruins, 
		player, enemy1, enemy2, enemy3, enemy4, shabEnemy1, shabEnemy2,
		shabayev, shabOnFoot, playerEnemy1,
		recy,
		creature1,creature2,creature3,creature4,
		oldPlayer,
		hunter,
		artil,
		gtow,
		h_last;

	// integers
	int
		i_first, ivtankCount, ivrcktCount, ivturrCount, ivscavCount, ibpgenCount,
		i, missionState, shabState,
		harrass_count,
		comp_team,
		movie_counter,
		artil_counter,
		i_last;
};

DLLBase *BuildMission(void)
{
	return new isdf07Mission();
}

void isdf07Mission::Setup(void)
{
	SetAutoGroupUnits(false);
	/*
		Here's where you set the values at the start.  
	*/
	next_unit=false;
	startDone=false;
	recyDeployed = false;
	constBuilt = false;
	scavBuilt = false;
	powerBuilt = false;
	gunTowBuilt = false;
	creaturesAttack = false;
	wallsBuilt = false;
	ruinsDiscovered = false;
	shabOutOfVehicle = false;
	shabHasOrder = false;
	shabState = 0;
	relicFound = false;
	shabHurt = false;
	troopsAttacked = false;
	getNewOrder = false;
	playerOnFoot = false;
	justHoped = false;
	winMission = false;
	relayBuilt = false;
	reminderTimer = 0.0f;
	timeToFail = 0.0f;
	errorRemTime1 = 0.0f;
	errorRemTime2 = 0.0f;
	missionState = 0;
	ivtankCount = 0;
	ivrcktCount = 0;
	ivturrCount = 0;
	ivscavCount = 0;
	ibpgenCount = 0;
	movie_counter=0;
	player = NULL;
	shabayev = NULL;
	spawn1 = NULL;
	spawn2 = NULL;
	animal1 = NULL;
	spawn3 = NULL;
	ruins = NULL;
	enemy1 = NULL;
	enemy2 = NULL;
	enemy3 = NULL;
	enemy4 = NULL;
	creature1=NULL;
	creature2=NULL;
	creature3=NULL;
	creature4=NULL;
	shabEnemy1 = NULL;
	shabEnemy2 = NULL;
	shabOnFoot = NULL;
	playerEnemy1 = NULL;
	enemy1deployed = false;
	enemy2deployed = false;
	enemy3deployed = false;
	ship_blown_up = false;
	shab_dead=false;
	harrass_count=0;
	BugFix=0;
	comp_team=2;
	Ally(3,1);
	Ally(1,3);

/* The following variable must be added into any mission that would
like to use the cineractive editing tools. */

//	IFace_CreateFloat("script.cin.edit", 0.0);
//	IFace_CreateInteger("script.mission.state", 0);
	moviePlaying = true;
	BeginCin = false;
	BeginSeq = false;
}

void isdf07Mission::AddObject(Handle h) 
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (IsOdf2(h,"ibrecy"))
	{
		Handle temp=BuildObject("fvscout", comp_team, spawn1);
		Attack(temp, h, 1);
		recy=h;
		recyDeployed=true;
	}


	if ((!scavBuilt) && (IsOdf2(h,"ivscav"))) {
//		Handle temp=BuildObject("fvsent", comp_team, spawn1);
//		Attack(temp, h, 1);
		scavBuilt = true;
	}
	else if ((!powerBuilt) && (IsOdf2(h,"ibpgen")))	{
		powerBuilt = true;
	}		
	else if ((!wallsBuilt) && (IsOdf2(h,"ibwall"))) {
		wallsBuilt = true;
	}
		
	else if ((!constBuilt) && (IsOdf2(h,"ivcons"))) {
		SendEnemies(2, h);
		constBuilt = true;
	}
	else if ((!relayBuilt) && (IsOdf2(h,"ibcbun")))
	{
		SendEnemies(3,h);
		relayBuilt=true;
	}
	else if ((!gunTowBuilt) && (IsOdf2(h,"ibgtow"))) {
		SendEnemies(4, h);
		gtow=h;
		gunTowBuilt = true;
	}
	else if ((!shabOutOfVehicle) && (IsOdf2(h,"ispilo"))) {
		if (justHoped) {
			shabOnFoot = h;
			shabOutOfVehicle = true;
		}
	}
	else if ((shabOutOfVehicle) && (IsOdf2(h,"isuser"))) {
		playerOnFoot = true;
		oldPlayer=player;
	}

	if (IsOdf2(h,"ivtank")) { //react to player building a tank
			SendEnemies(0, h);

	}
	
	else if (IsOdf2(h,"ivrckt")) { //react to the player building a rocket tank
		SendEnemies(1, h);
	}
		
	else if (IsOdf2(h,"ivturr")) { //react to the player building a turret
		SendEnemies(3, h);
	}

}


void isdf07Mission::SendEnemies(int type, Handle target) {
	switch (type) {
		case 0: //tank
			if (!IsAlive(enemy1)) {
				enemy1 = BuildObject("fvtank", comp_team, spawn1);
				Attack(enemy1, target, 1);
			}
			break;
		case 1: //rocket
			if (!IsAlive(enemy1)) {
				enemy1 = BuildObject("fvsent", comp_team, spawn1);
				Attack(enemy1, target, 1);
			}
			if (!IsAlive(enemy2)) {
				enemy2 = BuildObject("fvsent", comp_team, spawn2);
				Attack(enemy2, target, 1);
			}
			break;
		case 2: //constructor
			if (!IsAlive(enemy1)) {
				enemy1 = BuildObject("fvtank", comp_team, spawn1);
				Attack(enemy1, target, 1);
			}
			break;
		case 3: //turret
			if (!IsAlive(enemy1)) {
				enemy1 = BuildObject("fvarch", 2, spawn1);
				Attack(enemy1, target, 1);
			}
			if (!IsAlive(enemy2)) {
				enemy2 = BuildObject("fvarch", 2, spawn2);
				Attack(enemy2, target, 1);
			}
			break;
		case 4: //gun tower
			SetIndependence(enemy1, 0);
			SetIndependence(enemy2, 0);
			enemy1 = BuildObject("fvtank", 2, spawn1);
			enemy2 = BuildObject("fvtank", 2, spawn2);
			enemy3 = BuildObject("fvsent", 2, spawn3);
			Attack(enemy1, target, 1);
			Attack(enemy2, target, 1);
			Defend2(enemy3, enemy1, 1);
			break;
	}
	// so we transform them later
	enemy1deployed=false;
	enemy2deployed=false;
}

void isdf07Mission::ProcessCommand(unsigned long crc) {

//	CinProcessCommand(crc);
	if (crc == 3663682790) {
		BeginCin = true;
	}
	if (crc == 220803983) {
		BeginSeq = true;
	}
 } 

void checkWing(Handle wingName, Handle player) {
	// this is checking to make sure the player does not attack his wingman /////////

	if ((IsAlive(wingName)) && (IsAlive(player)))
	{
		if (GetTime() - GetLastFriendShot(wingName) < .2f)
		{
		//	AudioMessage("shotwing.wav"); // (shab) //watch your firing!
		}
	}
}

void isdf07Mission::CommandShab() {
	char tempstr[128];
	switch (shabState) {
		case 0: //setup the first batch of enemies
			shabEnemy1 = BuildObject("fvsent", comp_team, spawn1);
			shabEnemy2 = BuildObject("fvsent", comp_team, spawn2);
			Attack(shabEnemy1, shabayev, 1);
			Attack(shabEnemy2, shabayev, 1);
			Attack(shabayev, shabEnemy1, 1);
			shabState++;
			break;
		case 1: //do nothing until the first enemy gets killed
			if (!IsAlive(shabEnemy1)) {
				if (IsAlive(shabEnemy2)) {
					Attack(shabayev, shabEnemy2, 1);
					shabState++;
				}
				else {
					shabState++;
				}
			}

			if (gunTowBuilt) { //If shab can't kill anybody do it for her
				Damage(shabEnemy1, 3000);
				if (IsAlive(shabEnemy2)) {
					Damage(shabEnemy2, 3000);
				}
				ClearObjectives();
				AddObjective("isdf0707.otf", WHITE);
				Goto(shabayev, "tree_point", 1);
				AudioMessage("isdf0728.wav");
				shabState = 3;
				BugFix=GetTime()+60.0f;
			}

			break;
		case 2: //go NEAR the ruin when all of the enemies are killed
			if ((missionState>8) && (IsAlive(shabEnemy2))) { //If shab can't kill anybody do it for her
				Damage(shabEnemy2, 3000);
			}
			if ((!IsAlive(shabEnemy1)) && (!IsAlive(shabEnemy2)) && (!gunTowBuilt)) {
				shabEnemy2 = BuildObject("fvsent", 2, spawn1);
				Attack(shabayev, shabEnemy2, 1);
				Attack(shabEnemy2, shabayev, 1);

			}
			if ((!IsAlive(shabEnemy1)) && (!IsAlive(shabEnemy2)) && (gunTowBuilt)) {
				ClearObjectives();
				AddObjective("isdf0710.otf", WHITE);
				AudioMessage("isdf0728.wav");
				Goto(shabayev, "tree_point", 1);
				BugFix=GetTime()+20.0f;
				shabState++;
			}
			break;
		case 3: //hop out of the vehicle when near the ruin
			if (GetTime()>BugFix)
			{
				Goto(shabayev,"tree_point");
				BugFix=GetTime()+10.0f;	
			}
			if (((GetDistance(shabayev, "tree_point") < 25.0)) && ((!IsAlive(enemy1)) || (!IsAlive(enemy2))))
			{
				ClearObjectives();
				AudioMessage("isdf0725.wav");

				AddObjective("isdf0707.otf", WHITE);
				justHoped = true;
				HopOut(shabayev);
//				SetObjectiveOn(shabOnFoot);
				hunter=	BuildObject("fvsent",comp_team,"hunter");
	//			Patrol(temp,"hunter_path");
				Attack(hunter,shabayev); // blow up shabs craft
				CameraReady();
				reminderTimer=GetTime()+60.0f;
				shabState++;
			}
			break;
		case 4:
			oldPlayer=HoppedOutOf(shabOnFoot);	// because shab becomes 0
			{
				Vector pos;
				pos = GetPosition(oldPlayer);
				CameraObject(oldPlayer,2,5,-7,oldPlayer);		
				LookAt(shabOnFoot, ruins, 1);
				RemoveObject(oldPlayer);
				oldPlayer=BuildObject("petank",1,pos);
			}
			shabState++;
			break;
		case 5:
			if (movie_counter<70)
			{
				CameraObject(oldPlayer,2,2,-7,oldPlayer);
				movie_counter++;
			}
			else
			{
				RemoveObject(oldPlayer);
				Handle temp=BuildObject("ibnav",1,"tree_point");
				TranslateString2(tempstr, sizeof(tempstr), "Mission0701");  // Rescue
				SetObjectiveName(temp,tempstr);
				SetObjectiveOn(temp);
				CameraFinish();
				shabState++;
			}
			break;
		case 6: //order the player to get out of his vehicle once he gets close
			if ((!IsAround(shabayev)) && (!ship_blown_up))
			{
				Patrol(hunter,"hunter_path");
				SetIndependence(hunter,0);
				ship_blown_up=true;

			}

			if ((!IsAlive(shabOnFoot) && (!shab_dead)))	
			{
				AudioMessage("isdf0732.wav");
				ClearObjectives();
				AddObjective("isdf05l1.otf",RED,15.0f);
				FailMission(GetTime()+5.0f,"isdf05l1.otf");
				shab_dead=true;
			}

			if (GetTime()>reminderTimer) {
				AudioMessage("isdf0725.wav");
				reminderTimer=GetTime()+60.0f;
			}
			
			if ((GetDistance(shabOnFoot, player) < 50.0)) {

				//RemoveObject(shabayev);
				Attack(shabEnemy1,shabayev);
				Attack(shabEnemy2,shabayev);
				ClearObjectives();
				AudioMessage("isdf0729.wav");
				AddObjective("isdf0708.otf", WHITE);
				shabState++;
			}
			break;

		case 7: //send shab to get the relic
			if ((!IsAlive(shabOnFoot) && (!shab_dead)))	
			{
				AudioMessage("isdf0732.wav");
				ClearObjectives();
				AddObjective("isdf05l1.otf",RED,15.0f);
				FailMission(GetTime()+5.0f,"isdf05l1.otf");
				shab_dead=true;
			}
			if (playerOnFoot) {
				Attack(shabEnemy1,oldPlayer);
				Attack(shabEnemy2,oldPlayer);
				Goto(shabOnFoot, ruins, 1);
				//we should start the patrols here
				shabState++;
			}
			break;
		case 8: //get shab hurt
			if ((!IsAlive(shabOnFoot) && (!shab_dead)))	
			{
				AudioMessage("isdf0732.wav");
				ClearObjectives();
				AddObjective("isdf05l1.otf",RED,15.0f);
				FailMission(GetTime()+5.0f,"isdf05l1.otf");
				shab_dead=true;
			}

			if ((GetDistance(shabOnFoot, ruins) < 20.0f) || (GetDistance(player,ruins)<10.0f))
			{
				if (winMission == false) {
					AudioMessage("isdf0731.wav"); // wrong file name
					SucceedMission(GetTime()+5.0f,"isdf07w1.txt");
					winMission = true;
				}
			}
			break;
		case 9: //hide shab
			
			break;
		case 10: //play closing cineractive
		// The following is an example of how to play a movie in a script.
			moviePlaying = PlayMovie("temp");
			if (!moviePlaying) {
				missionState++;
				moviePlaying = true;
				//IFace_SetInteger("script.mission.state", 1);
			}
			break;
	}

	if (GetHealth(shabayev) < 0.7f) { //keep shab alive
		AddHealth(shabayev, 100);
	}

	if ((GetAmmo(shabayev)) < 0.5f) {
		AddAmmo(shabayev, 500);
	}
	if ((justHoped) && (!IsAlive(shabOnFoot)))
	{
		int i;
		i=1;
		// Houston we have a problem
	}

}

void isdf07Mission::handlePlayerMistakes() {
	if (missionState < 6) {	//Not enough scrap
		if ((missionState>3) &&
			(GetScrap(1) < 6) && (GetTime() > errorRemTime1)) {
			ClearObjectives();
			AddObjective("isdf0709.otf", WHITE);
			AudioMessage("isdf0709.wav");
			errorRemTime1 = (GetTime() + 60.0f);
		}


	}

	if (!IsAlive(shabayev)) {	//kills shabayev
	//	AudioMessage("Demo0304.wav"); // "Cooke.  You're being shipped back to Earth where you'll face court marshall for killing a commanding officer.
	//	FailMission(GetTime() + 15.0f);
	}

/*	if (!IsAlive(player)) { //gets killed
	//	AudioMessage("Demo0304.wav"); // you loose go to shell screen
		FailMission(GetTime() + 15.0f);
	}*/

	if (missionState == 6) {//does not follow shabayev
		if ((GetDistance(player, shabayev) > 400.0f) && (GetTime() < timeToFail)) {
		//	AudioMessage("tooFar.wav"); //"Cooke, you're getting too far from my wing.  Fall in.
			timeToFail = GetTime() + 60.0f;
		}
		else 
		if (GetDistance(player, shabayev) < 400.0f) {
			timeToFail = 0.0f;
		}


	}
	if (missionState == 7) {//does not get out of his vehicle

	}
	if (missionState == 9) {//ignores shabayev's need for help
		if ((GetDistance(player, shabayev) > 40.0f) && (GetTime() < timeToFail)) {
		//	AudioMessage("tooFar.wav"); //"Cooke, you're getting too far from my wing.  Fall in.
			timeToFail = GetTime() + 60.0f;
		}
		if  (GetDistance(player, shabayev) < 40.0f) {
			timeToFail = 0.0f;
		}

	}
}


void isdf07Mission::playEndCin() {
}

void isdf07Mission::Execute(void) {

	
/* The following is needed for editing cineractives. */	
	if (BeginCin == true) {
		BeginCin = PlayMove();
	}

	if (BeginSeq == true) {
		char temp[20] = "***";
		BeginSeq = PlayMovie(temp);
	}
	if (IFace_GetFloat("script.cin.edit") == 1.0) {
//		cinToolSetup();
		IFace_SetFloat("script.cin.edit", 0.0);
	}
/* The above is needed for editing cineractives. */



	
	player = GetPlayerHandle();

	//This section evaluates what has happened.
	checkWing(shabayev, player); //Did we hurt our friendly instructor.
	switch (missionState) {
		case 0: //This will do the setup for the mission.
			spawn1 = GetHandle("spawn_1");
			spawn2 = GetHandle("spawn_2");
			spawn3 = GetHandle("spawn_3");
			creature1=BuildObject("mcjak01",0,"creature1");
			creature2=BuildObject("mcjak01",0,"creature2");
			creature3=BuildObject("mcjak01",0,"creature3");
			creature4=BuildObject("mcjak01",0,"creature4");

			shabayev = BuildObject("ivtank",3,"spawn_shab");
			recy = GetHandle("recycler");
			ruins = GetHandle("ruins");
			SetScrap(1, 40);
//			playerEnemy1 = BuildObject("fvtank", 2, spawn3);
//			Attack(playerEnemy1, player, 1);
			CommandShab();
			AudioMessage("isdf0701.wav");
			AudioMessage("isdf0740.wav");
			AudioMessage("isdf0702.wav");
			AudioMessage("isdf0703.wav");
			SetSkill(shabayev,3);
			SendEnemies(0,player);
			{
				// brad added
				int poolHandle = GetHandle(288);
				SpawnBirds(1, 5, "mcwing01", 0, poolHandle, poolHandle);
			}
			missionState++;
			break;
		case 1: //Check to see if the player has deployed their recycler.
			if (!getNewOrder) {
				ClearObjectives();
				AudioMessage("isdf0704.wav");
				AddObjective("isdf0701.otf", WHITE);
				reminderTimer = (GetTime() + 60.0f);
				if (!IsAlive(animal1)) {
					animal1 = BuildObject("mcjak01", 2, spawn3); //This will be changed to the animal
					Goto(animal1, recy);
					SetIndependence(animal1, 0);
				}
				getNewOrder = true;
			}

			//	recyDeployed = IsDeployed(recy);
			if (recyDeployed) {
				AudioMessage("isdf0706.wav");
				missionState++;
				getNewOrder = false;
			}
			if ((IsAlive(playerEnemy1)) && (!enemy1deployed) &&
				(GetDistance(recy,playerEnemy1)<100.0f))
			{
				enemy1deployed=true;
			}
			if ((!IsAlive(playerEnemy1)) && (!IsAlive(enemy1))) {
				playerEnemy1 = BuildObject("fvtank", comp_team, spawn3);
				Attack(playerEnemy1, player, 1);
			}
			break;
		case 2: //Check to see if the player has built a scavenger.
			if (!getNewOrder) {
				ClearObjectives();
				AddObjective("isdf0702.otf", WHITE);
				reminderTimer = (GetTime() + 60.0f);
				AudioMessage("isdf0708.wav");
				getNewOrder = true;
			}
			if (scavBuilt) {
				AudioMessage("isdf0707.wav");
				reminderTimer = (GetTime() + 30.0f);
				missionState++;
				getNewOrder = false;
			}
			if ((IsAlive(playerEnemy1)) && (!enemy1deployed) &&
				(GetDistance(recy,playerEnemy1)<100.0f))
			{
				enemy1deployed=true;
			}
			if ((!IsAlive(playerEnemy1)) && (!IsAlive(enemy1))) {
				playerEnemy1 = BuildObject("fvtank", 2, spawn3);
				Attack(playerEnemy1, player, 1);
			}

			break;
		case 3: //Check to see if the player has built a construction rig.
			if (!getNewOrder) {
				ClearObjectives();
				AddObjective("isdf0703.otf", WHITE);
				AudioMessage("isdf0710.wav");
				reminderTimer = (GetTime() + 60.0f);
				getNewOrder = true;
			}
			if ((IsAlive(playerEnemy1)) && (!enemy1deployed) &&
				(GetDistance(recy,playerEnemy1)<100.0f))
			{
				enemy1deployed=true;
			}
			if (constBuilt) {
				missionState++;
				getNewOrder = false;
			}
			break;
		case 4: //Check to see if the player has built a power plant.
			if (!getNewOrder) {
				ClearObjectives();
				AddObjective("isdf0704.otf", WHITE);
				AudioMessage("isdf0714.wav");
				reminderTimer = (GetTime() + 60.0f);
				getNewOrder = true;
			}
			if (powerBuilt) {
				missionState++;
				getNewOrder = false;
			}
			if ((!IsAlive(playerEnemy1)) && (!IsAlive(enemy1))) {
				playerEnemy1 = BuildObject("fvtank", 2, spawn3);
				Attack(playerEnemy1, player, 1);

			}

			break;
		case 5:  // check to see if the player has built a relay bunker
			if (!getNewOrder) {
				ClearObjectives();
				AddObjective("isdf0705.otf", WHITE);
				AudioMessage("isdf0716.wav");
				reminderTimer = (GetTime() + 60.0f);
				getNewOrder = true;
			}
			if (relayBuilt) {
				missionState++;
				getNewOrder = false;
			}

			break;
		case 6: //Check to see if the player has built a gun tower
			if (!getNewOrder) {
				ClearObjectives();
				AddObjective("isdf0706.otf", WHITE);
				AudioMessage("isdf0719.wav");
				reminderTimer = (GetTime() + 60.0f);
				getNewOrder = true;
			}
			if (gunTowBuilt) 
			{
				missionState++;
				artil=BuildObject("fvartl",2,"artil");
				Goto(artil,"artillery");
				Handle temp=BuildObject("fvscout",2,spawn2);
				Follow(temp,artil);
				BuildObject("fvscout",2,spawn3);
				Follow(temp,artil);
				artil_counter=0;
				getNewOrder = false;
			}
			break;
		case 7:  // now they will use artillery
			artil_counter++;
			if (artil_counter==300)
			{
				Attack(artil,gtow);
		//		CameraReady();
			}
			if ((artil_counter>300) & (artil_counter<355))
			{
		//		CameraObject(artil,12,8,3,artil);
			}
			if (artil_counter==355)
			{
		//		CameraFinish();
				missionState++;
			}
			// cheesy code but I am tired
			break;
		case 8:
			if (!IsAlive(artil))
			{
				missionState++;
			}
			break;
	
	}
	float currentTime = GetTime();
	if ((reminderTimer < currentTime) && (getNewOrder)) { //This checks to see if we should remind the player of his order.
		getNewOrder = false;
	}
	harrass_count++;
	if (harrass_count%701==0)
	{
		SendEnemies(1,player);
	}
	CommandShab();
	handlePlayerMistakes();
	if (shabState<3) {
		if ((!IsAlive(shabayev) && (!shab_dead)))	
		{
			AudioMessage("isdf0732.wav");
			ClearObjectives();
			AddObjective("isdf05l1.otf",RED,15.0f);
			FailMission(GetTime()+5.0f,"isdf05l1.otf");
			shab_dead=true;
		}
	}

	if ((!IsAround(recy)) && (!shab_dead))
	{
		FailMission(GetTime()+5.0f,"isdf05l1.otf");
		shab_dead=true;
	}


}
