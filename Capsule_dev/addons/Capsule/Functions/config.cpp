class CfgPatches
{
	class Capsule_Functions
	{
		addonRootClass="Capsule";
		requiredAddons[]=
		{
			"A3_Functions_F_Jets",
			"Capsule"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
	};
};
class CfgFunctions
{
	class A3
	{
		class Ambient
		{
			class animalBehaviour
			{
				description="Animal behaviour control. Called by Animals_F\Data\Scripts\main.fsm.";
				headerType=1;
				file="\Capsule\Functions\fn_animalbehaviour.sqf";
			};
		};
		class HoldActions
		{
			class holdAction_animationTimerCode
			{
				file="\Capsule\Functions\HoldActions\fn_holdAction_animationTimerCode.sqf";
			};
		};
		class Respawn
		{
			class showRespawnMenuPositionList
			{
				file = "\Capsule\Functions\Respawn\fn_showRespawnMenuPositionList.sqf";
			};
		};
	};
	class A3_Jets
	{
		class AircrfatCarrier
		{
			class Carrier01AnimateDeflectors
			{
				description="This O&T Expasnion Eden mod change vanilla function with fixes for MP, overite of vanilla class will deleted on Arma 3 dev fix. see FT ticket T174022";
				file="\Capsule\Functions\fn_carrier01animatedeflectors.sqf";
			};
		};
		class AircraftFunctionality
		{
			class AircraftTailhookAi
			{
				description="This O&T Expasnion Eden mod change vanilla function with fixes for MP, overite of vanilla class will deleted on Arma 3 dev fix. see FT ticket T174022";
				file="\Capsule\Functions\fn_AircraftTailhookAi.sqf";
			};
		};
		class CarrierOps
		{
			class AircraftTailhook
			{
				description="This O&T Expasnion Eden mod change vanilla function with fixes for MP, overite of vanilla class will deleted on Arma 3 dev fix. see FT ticket T174022";
				file="\Capsule\Functions\fn_aircraftTailhook.sqf";
			};
		};
		class Ejection
		{
			class PlaneEjection
			{
				description="This O&T Expasnion Eden mod change vanilla function with fixes for MP, overite of vanilla class will deleted on Arma 3 dev fix. see FT ticket T174022";
				file="\Capsule\Functions\fn_planeEjection.sqf";
			};
			class PlaneEjectionFX
			{
				description="This O&T Expasnion Eden mod change vanilla function with fixes for MP, overite of vanilla class will deleted on Arma 3 dev fix. see FT ticket T174022";
				file="\Capsule\Functions\fn_planeEjectionFX.sqf";
			};
			class EjectionSeatRelease
			{
				description="This O&T Expasnion Eden mod change vanilla function with fixes for MP, overite of vanilla class will deleted on Arma 3 dev fix. see FT ticket T174022";
				file="\Capsule\Functions\fn_ejectionSeatRelease.sqf";
			};
		};
	};
	class Globe
	{
		tag="Globe";
		project="Globe";
		class Ambient
		{
			class animalBehaviour
			{
				file="\Capsule\Functions\fn_animalbehaviourInitMP.sqf";
			};
		};
	};
};
