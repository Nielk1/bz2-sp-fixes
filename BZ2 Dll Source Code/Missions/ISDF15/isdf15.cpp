#include "..\Shared\SPMission.h"

class Misn04Mission : public SPMission 
{
public:
	Misn04Mission(void)
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
		b_last;

	// floats
	float
		f_first,

		f_last;

	// handles
	Handle
		h_first,
		player,
		h_last;

	// integers
	int
		i_first,

		i_last;
};

DLLBase * BuildMission(void)
{
	return new Misn04Mission();
}

void Misn04Mission::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	start_done = false;


//  floats


//  handles
	player = GetPlayerHandle();



//  integers


}

void Misn04Mission::AddObject(Handle h)
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

void Misn04Mission::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/

	player = GetPlayerHandle();



}
