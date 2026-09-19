class CfgPatches
{
	class Capsule
	{
		author="Trager";
		name="O&T Expansion Eden: Standalone - Capsule";
		url="https://steamcommunity.com/workshop/filedetails/?id=1923321700";
		requiredAddons[]=
		{
			"A3_Data_F_Decade_Loadorder"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
	};
};
class CfgMods
{
	class Mod_Base;
	class Capsule: Mod_Base
	{
		dir="Capsule";
		name="Capsule";
		nameShort="Capsule";
		author="Trager";
		authors[]=
		{
			"O&T Expansion Eden"
		};
		overview="Vanilla bug fix mod.";
		fieldManualTopicAndHint[]={};
		dlcColor[]={0.698039,0.70588201,0.0039215698,1};
		action="https://steamcommunity.com/workshop/filedetails/?id=1923321700";
		picture="Capsule\Data\Logos\Capsule_picture_ca.paa";
		logo="Capsule\Data\Logos\Capsule_logo_ca.paa";
		logoOver="Capsule\Data\Logos\Capsule_logoOver_ca.paa";
		logoSmall="Capsule\Data\Logos\Capsule_logo_small_ca.paa";
		logoTitle="Capsule\Data\Logos\Capsule_picture_ca.paa";
		hideName=0;
		hidePicture=0;
		overviewText="Vanilla bug fix mod.";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class Capsule
		{
			list[]=
			{
				"Capsule",
				"Capsule_Enoch",
				"Capsule_Apex",
				"Capsule_Functions",
				"Capsule_Loadorder"
			};
		};
	};
};
class CfgVehicles
{
	class Plane_Base_F;
	class Car_F;
	class Items_base_F;
	class Books_base_F: Items_base_F
	{
		delete ObjectTextureCustom0;
		class Attributes
		{
			class ObjectTextureCustom0
			{
				displayName="$STR_3den_object_attribute_objecttexturecustom0_displayname";
				tooltip="$STR_3den_object_attribute_objecttexturecustom_tooltip";
				property="ObjectTextureCustom0";
				control="Edit";
				expression="_this setObjectTextureGlobal [0,_value]";
				defaultValue="(getObjectTextures _this) param [0,'',['']]";
			};
		};
	};
	class Newspaper_base_F: Items_base_F
	{
		delete ObjectTextureCustom0;
		class Attributes
		{
			class ObjectTextureCustom0
			{
				displayName="$STR_3den_object_attribute_objecttexturecustom0_displayname";
				tooltip="$STR_3den_object_attribute_objecttexturecustom_tooltip";
				property="ObjectTextureCustom0";
				control="Edit";
				expression="_this setObjectTextureGlobal [0,_value]";
				defaultValue="(getObjectTextures _this) param [0,'',['']]";
			};
		};
	};
	class MRAP_03_base_F: Car_F
	{
		soundEngineOnInt[]=
		{
			"A3\Sounds_F\vehicles2\soft\Mrap_03\Mrap_03_Engine_Int_Start",
			1,
			1
		};
		soundEngineOffInt[]=
		{
			"A3\Sounds_F\vehicles2\soft\Mrap_03\Mrap_03_Engine_Int_stop",
			1,
			1
		};
	};
	class MRAP_02_base_F: Car_F
	{
		soundEngineOnInt[]=
		{
			"A3\Sounds_F\vehicles2\soft\Mrap_02\Mrap_02_Engine_Int_Start",
			1,
			1
		};
		soundEngineOffInt[]=
		{
			"A3\Sounds_F\vehicles2\soft\Mrap_02\Mrap_02_Engine_Int_stop",
			1,
			1
		};
	};
	class SUV_01_base_F: Car_F
	{
		extCameraPosition[] = { 0, 2, -8.75 };
	};
	class SoundSetSource_01_base_F;
	class Truck_02_base_F;
	class LandVehicle;
	class Tank_F;
	class Helicopter;
	class Truck_F;
	class Animal;
	class Animal_Base_F: Animal
	{
		class EventHandlers
		{
			class Globe_animalBehaviourMP
			{
				postInit="[(_this # 0)] call Globe_fnc_animalBehaviour";
			};
		};
	};
	class Plane_Fighter_01_Base_F: Plane_Base_F
	{
		class UserActions
		{
			class Plane_Fighter_01_Eject;
			class Plane_Fighter_01_tailhook_down: Plane_Fighter_01_Eject
			{
				statement="this animate ['tailhook',0]; this animate ['tailhook_door_l',0]; this animate ['tailhook_door_r',0]; this SetUserMFDvalue [4,1]; [this] spawn BIS_fnc_AircraftTailhook; [ [this], { params ['_veh']; if (player in _veh) then { playSound 'Plane_Fighter_01_tailhook_down_sound'} else { _veh say3D ['Plane_Fighter_01_tailhook_down_sound', 100, 1, false]; }; }] remoteExec ['spawn', 0];";
			};
			class Plane_Fighter_01_tailhook_up: Plane_Fighter_01_tailhook_down
			{
				statement="this animate ['tailhook',1]; this animate ['tailhook_door_l',1]; this animate ['tailhook_door_r',1]; this SetUserMFDvalue [4,0]; [ [this], { params ['_veh']; if (player in _veh) then { playSound 'Plane_Fighter_01_tailhook_up_sound'; } else { _veh say3D ['Plane_Fighter_01_tailhook_up_sound', 100, 1, false]; }; } ] remoteExec ['spawn', 0];";
			};
			class Plane_Fighter_01_fold_wings: Plane_Fighter_01_Eject
			{
				statement="this animate ['wing_fold_l',1]; this animate ['wing_fold_r',1]; this animate ['wing_fold_cover_l',1]; this animate ['wing_fold_cover_r',1]; [this, ['Plane_Fighter_01_foldwing_sound', 150, 1, 0, 0, false]] remoteExecCall ['say3D'];";
			};
			class Plane_Fighter_01_unfold_wings: Plane_Fighter_01_fold_wings
			{
				statement="this animate ['wing_fold_l',0]; this animate ['wing_fold_r',0]; this animate ['wing_fold_cover_l',0]; this animate ['wing_fold_cover_r',0]; [this, ['Plane_Fighter_01_foldwing_sound', 150, 1, 0, 0, false]] remoteExecCall ['say3D'];";
			};
		};
	};
	class SoundSetSource_Sfx_Dog: SoundSetSource_01_base_F
	{
		class Sounds
		{
			soundSets[]=
			{
				"Sfx_Dog_SoundSet",
				"Sfx_Dog_Distant_SoundSet"
			};
		};
		class EventHandlers
		{
			init="(_this # 0) spawn {sleep 5; deleteVehicle _this};";
		};
	};
	class ParachuteBase: Helicopter
	{
		soundGetIn[]=
		{
			"a3\sounds_f\characters\parachute\parachute_open",
			0.94999999,
			1,
			200
		};
		soundGetOut[]=
		{
			"a3\sounds_f\characters\parachute\parachute_landing",
			0.69999999,
			1,
			150
		};
		class Eventhandlers
		{
			class Globe_ParachuteOpeningSFX
			{
				getIn="playSound3D ['a3\sounds_f\characters\parachute\parachute_open.wss', (_this#0), false, getPosASL (_this#0), 0.94999999, 1, 200, 0, true]";
			};
		};
	};
	class Offroad_01_base_F: Car_F
	{
		class Sounds
		{
			soundSets[]=
			{
				"Van_02_PoliceSiren_01_Ext_SoundSet",
				"Van_02_PoliceSiren_01_Int_SoundSet"
			};
			soundSetsInt[]=
			{
				"Offroad_01_Engine_RPM0_INT_SoundSet",
				"Offroad_01_Engine_RPM1_INT_SoundSet",
				"Offroad_01_Engine_RPM2_INT_SoundSet",
				"Offroad_01_Engine_RPM3_INT_SoundSet",
				"Offroad_01_Engine_RPM4_INT_SoundSet",
				"Offroad_01_Rattling_INT_SoundSet",
				"Offroad_01_Stress_INT_SoundSet",
				"Offroad_01_Rain_INT_SoundSet",
				"Offroad_01_Tires_Rock_Fast_OPEN_SoundSet",
				"Offroad_01_Tires_Grass_Fast_OPEN_SoundSet",
				"Offroad_01_Tires_Sand_Fast_OPEN_SoundSet",
				"Offroad_01_Tires_Gravel_Fast_OPEN_SoundSet",
				"Offroad_01_Tires_Mud_Fast_OPEN_SoundSet",
				"Offroad_01_Tires_Asphalt_Fast_OPEN_SoundSet",
				"Offroad_01_Tires_Water_Fast_OPEN_SoundSet",
				"Offroad_01_Tires_Rock_Slow_OPEN_SoundSet",
				"Offroad_01_Tires_Grass_Slow_OPEN_SoundSet",
				"Offroad_01_Tires_Sand_Slow_OPEN_SoundSet",
				"Offroad_01_Tires_Gravel_Slow_OPEN_SoundSet",
				"Offroad_01_Tires_Mud_Slow_OPEN_SoundSet",
				"Offroad_01_Tires_Asphalt_Slow_OPEN_SoundSet",
				"Offroad_01_Tires_Water_Slow_OPEN_SoundSet",
				"Offroad_01_Tires_Turn_Hard_OPEN_SoundSet",
				"Offroad_01_Tires_Turn_Soft_OPEN_SoundSet",
				"Offroad_01_Tires_Brake_Hard_OPEN_SoundSet",
				"Offroad_01_Tires_Brake_Soft_OPEN_SoundSet",
				"Tires_Movement_Dirt_Int_01_SoundSet"
			};
			soundSetsExt[]=
			{
				"Offroad_01_Engine_RPM0_EXT_SoundSet",
				"Offroad_01_Engine_RPM1_EXT_SoundSet",
				"Offroad_01_Engine_RPM2_EXT_SoundSet",
				"Offroad_01_Engine_RPM3_EXT_SoundSet",
				"Offroad_01_Engine_RPM4_EXT_SoundSet",
				"Offroad_01_Rattling_EXT_SoundSet",
				"Offroad_01_Stress_EXT_SoundSet",
				"Offroad_01_Rain_EXT_SoundSet",
				"Offroad_01_Tires_Rock_Fast_EXT_SoundSet",
				"Offroad_01_Tires_Grass_Fast_EXT_SoundSet",
				"Offroad_01_Tires_Sand_Fast_EXT_SoundSet",
				"Offroad_01_Tires_Gravel_Fast_EXT_SoundSet",
				"Offroad_01_Tires_Mud_Fast_EXT_SoundSet",
				"Offroad_01_Tires_Asphalt_Fast_EXT_SoundSet",
				"Offroad_01_Tires_Water_Fast_EXT_SoundSet",
				"Offroad_01_Tires_Rock_Slow_EXT_SoundSet",
				"Offroad_01_Tires_Grass_Slow_EXT_SoundSet",
				"Offroad_01_Tires_Sand_Slow_EXT_SoundSet",
				"Offroad_01_Tires_Gravel_Slow_EXT_SoundSet",
				"Offroad_01_Tires_Mud_Slow_EXT_SoundSet",
				"Offroad_01_Tires_Asphalt_Slow_EXT_SoundSet",
				"Offroad_01_Tires_Water_Slow_EXT_SoundSet",
				"Offroad_01_Tires_Turn_Hard_EXT_SoundSet",
				"Offroad_01_Tires_Turn_Soft_EXT_SoundSet",
				"Offroad_01_Tires_Brake_Hard_EXT_SoundSet",
				"Offroad_01_Tires_Brake_Soft_EXT_SoundSet",
				"Tires_Movement_Dirt_Ext_01_SoundSet"
			};
		};
	};
	class Van_02_base_F: Truck_F
	{
		class Sounds
		{
			soundSets[]=
			{
				"Van_02_PoliceSiren_01_Int_SoundSet",
				"Van_02_PoliceSiren_01_Ext_SoundSet"
			};
			soundSetsInt[]=
			{
				"Van_02_Eng_01_Idle_Int_SoundSet",
				"Van_02_Eng_01_Rpm_01_Int_SoundSet",
				"Van_02_Eng_01_Rpm_02_Int_SoundSet",
				"Van_02_Eng_01_Rpm_03_Int_SoundSet",
				"Van_02_Eng_01_Rpm_04_Int_SoundSet",
				"Van_02_Eng_01_Rpm_05_Int_SoundSet",
				"Van_02_Noise_Hard_01_Int_SoundSet",
				"Van_02_Tires_Gravel_01_Int_SoundSet",
				"Van_02_Tires_Asphalt_01_Int_SoundSet",
				"Van_02_Tires_Grass_Mud_01_Int_SoundSet",
				"Van_02_Tires_Sand_01_Int_SoundSet",
				"Van_02_Tires_Rock_01_Int_SoundSet",
				"Van_02_Tires_Water_01_Int_SoundSet",
				"Van_02_Brakes_Asphalt_01_Int_SoundSet",
				"Van_02_TurnLeft_Asphalt_01_Int_SoundSet",
				"Van_02_TurnRight_Asphalt_01_Int_SoundSet",
				"Van_02_Brakes_Dirt_01_Int_SoundSet",
				"Van_02_Tires_Movement_Dirt_Int_01_SoundSet",
				"Van_02_Rain_01_Int_SoundSet"
			};
			soundSetsExt[]=
			{
				"Van_02_Eng_01_Idle_Ext_SoundSet",
				"Van_02_Eng_01_Rpm_01_Ext_SoundSet",
				"Van_02_Eng_01_Rpm_02_Ext_SoundSet",
				"Van_02_Eng_01_Rpm_03_Ext_SoundSet",
				"Van_02_Eng_01_Rpm_04_Ext_SoundSet",
				"Van_02_Eng_01_Rpm_05_Ext_SoundSet",
				"Van_02_Tires_Gravel_01_Ext_SoundSet",
				"Van_02_Tires_Asphalt_01_Ext_SoundSet",
				"Van_02_Tires_Grass_Mud_01_Ext_SoundSet",
				"Van_02_Tires_Sand_01_Ext_SoundSet",
				"Van_02_Tires_Rock_01_Ext_SoundSet",
				"Van_02_Tires_Water_01_Ext_SoundSet",
				"Van_02_Brakes_Asphalt_01_Ext_SoundSet",
				"Van_02_TurnLeft_Asphalt_01_Ext_SoundSet",
				"Van_02_TurnRight_Asphalt_01_Ext_SoundSet",
				"Van_02_Brakes_Dirt_01_Ext_SoundSet",
				"Van_02_TurnLeft_Dirt_01_Ext_SoundSet",
				"Van_02_TurnRight_Dirt_01_Ext_SoundSet",
				"Van_02_Tires_Movement_Dirt_Ext_01_SoundSet",
				"Van_02_Rain_01_Ext_SoundSet"
			};
		};
	};
	class Van_02_medevac_base_F: Van_02_base_F
	{
		class Sounds
		{
			soundSets[]=
			{
				"Van_02_AmbulanceSiren_01_Int_SoundSet",
				"Van_02_AmbulanceSiren_01_Ext_SoundSet"
			};
			soundSetsInt[]=
			{
				"Van_02_Eng_01_Idle_Int_SoundSet",
				"Van_02_Eng_01_Rpm_01_Int_SoundSet",
				"Van_02_Eng_01_Rpm_02_Int_SoundSet",
				"Van_02_Eng_01_Rpm_03_Int_SoundSet",
				"Van_02_Eng_01_Rpm_04_Int_SoundSet",
				"Van_02_Eng_01_Rpm_05_Int_SoundSet",
				"Van_02_Noise_Hard_01_Int_SoundSet",
				"Van_02_Tires_Gravel_01_Int_SoundSet",
				"Van_02_Tires_Asphalt_01_Int_SoundSet",
				"Van_02_Tires_Grass_Mud_01_Int_SoundSet",
				"Van_02_Tires_Sand_01_Int_SoundSet",
				"Van_02_Tires_Rock_01_Int_SoundSet",
				"Van_02_Tires_Water_01_Int_SoundSet",
				"Van_02_Brakes_Asphalt_01_Int_SoundSet",
				"Van_02_TurnLeft_Asphalt_01_Int_SoundSet",
				"Van_02_TurnRight_Asphalt_01_Int_SoundSet",
				"Van_02_Brakes_Dirt_01_Int_SoundSet",
				"Van_02_Tires_Movement_Dirt_Int_01_SoundSet",
				"Van_02_Rain_01_Int_SoundSet"
			};
			soundSetsExt[]=
			{
				"Van_02_Eng_01_Idle_Ext_SoundSet",
				"Van_02_Eng_01_Rpm_01_Ext_SoundSet",
				"Van_02_Eng_01_Rpm_02_Ext_SoundSet",
				"Van_02_Eng_01_Rpm_03_Ext_SoundSet",
				"Van_02_Eng_01_Rpm_04_Ext_SoundSet",
				"Van_02_Eng_01_Rpm_05_Ext_SoundSet",
				"Van_02_Tires_Gravel_01_Ext_SoundSet",
				"Van_02_Tires_Asphalt_01_Ext_SoundSet",
				"Van_02_Tires_Grass_Mud_01_Ext_SoundSet",
				"Van_02_Tires_Sand_01_Ext_SoundSet",
				"Van_02_Tires_Rock_01_Ext_SoundSet",
				"Van_02_Tires_Water_01_Ext_SoundSet",
				"Van_02_Brakes_Asphalt_01_Ext_SoundSet",
				"Van_02_TurnLeft_Asphalt_01_Ext_SoundSet",
				"Van_02_TurnRight_Asphalt_01_Ext_SoundSet",
				"Van_02_Brakes_Dirt_01_Ext_SoundSet",
				"Van_02_TurnLeft_Dirt_01_Ext_SoundSet",
				"Van_02_TurnRight_Dirt_01_Ext_SoundSet",
				"Van_02_Tires_Movement_Dirt_Ext_01_SoundSet",
				"Van_02_Rain_01_Ext_SoundSet"
			};
		};
	};
	class MBT_02_base_F: Tank_F
	{
		class Sounds
		{
			soundSetsInt[]=
			{
				"MBT_02_Engine_RPM0_INT_SoundSet",
				"MBT_02_Engine_RPM1_INT_SoundSet",
				"MBT_02_Engine_RPM2_INT_SoundSet",
				"MBT_02_Engine_RPM3_INT_SoundSet",
				"MBT_02_Engine_INT_Burst_SoundSet",
				"MBT_02_Tracks_01_INT_SoundSet",
				"MBT_02_Tracks_02_INT_SoundSet",
				"MBT_02_Tracks_03_INT_SoundSet",
				"MBT_02_Tracks_04_INT_SoundSet",
				"MBT_02_Tracks_05_INT_SoundSet",
				"MBT_02_Tracks_06_INT_SoundSet",
				"MBT_02_Interior_Tone_Engine_Off_SoundSet",
				"MBT_02_Interior_Tone_Engine_On_SoundSet",
				"MBT_02_Rattling_INT_SoundSet",
				"MBT_02_Rain_INT_SoundSet",
				"MBT_02_Tracks_Brake_Hard_INT_SoundSet",
				"MBT_02_Tracks_Brake_Soft_INT_SoundSet",
				"MBT_02_Tracks_Turn_Hard_INT_SoundSet",
				"MBT_02_Tracks_Turn_Soft_INT_SoundSet",
				"MBT_02_Drive_Water_INT_SoundSet",
				"MBT_02_Drive_Dirt_INT_SoundSet",
				"MBT_02_Turbine01_Int_Tonal_SoundSet",
				"MBT_02_Turbine01_Int_Noisy_SoundSet",
				"MBT_02_Servo01_Int_SoundSet",
				"MBT_02_Servo02_Int_SoundSet",
				"Tracks_Movement_Dirt_Int_01_SoundSet",
				"Tracks_Surface_Soft_Int_SoundSet",
				"Tracks_Surface_Hard_Int_SoundSet",
				"Tracks_Surface_Sand_Int_SoundSet",
				"Tracks_Surface_Squeaks_Soft_Int_SoundSet",
				"Tracks_Surface_Squeaks_Hard_Int_SoundSet",
				"Tanks_Material_Strain_Int_SoundSet",
				"Tank_General_Collision_Int_SoundSet"
			};
			soundSetsExt[]=
			{
				"MBT_02_Engine_RPM0_EXT_SoundSet",
				"MBT_02_Engine_RPM1_EXT_SoundSet",
				"MBT_02_Engine_RPM2_EXT_SoundSet",
				"MBT_02_Engine_RPM3_EXT_SoundSet",
				"MBT_02_Engine_EXT_Burst_SoundSet",
				"MBT_02_Tracks_01_EXT_SoundSet",
				"MBT_02_Tracks_02_EXT_SoundSet",
				"MBT_02_Tracks_03_EXT_SoundSet",
				"MBT_02_Tracks_04_EXT_SoundSet",
				"MBT_02_Tracks_05_EXT_SoundSet",
				"MBT_02_Tracks_06_EXT_SoundSet",
				"MBT_02_Rain_EXT_SoundSet",
				"MBT_02_Tracks_Brake_Hard_EXT_SoundSet",
				"MBT_02_Tracks_Brake_Soft_EXT_SoundSet",
				"MBT_02_Tracks_Turn_Hard_EXT_SoundSet",
				"MBT_02_Tracks_Turn_Soft_EXT_SoundSet",
				"MBT_02_Drive_Water_EXT_SoundSet",
				"MBT_02_Drive_Dirt_EXT_SoundSet",
				"MBT_02_Turbine01_Ext_Front_Tonal_SoundSet",
				"MBT_02_Turbine01_Ext_Rear_Tonal_SoundSet",
				"MBT_02_Turbine01_Ext_Front_Noisy_SoundSet",
				"MBT_02_Turbine01_Ext_Rear_Noisy_SoundSet",
				"MBT_02_Servo01_Ext_SoundSet",
				"MBT_02_Servo02_Ext_SoundSet",
				"Tracks_Movement_Dirt_Ext_01_SoundSet",
				"Tracks_Surface_Soft_Ext_SoundSet",
				"Tracks_Surface_Hard_Ext_SoundSet",
				"Tracks_Surface_Sand_Ext_SoundSet",
				"Tracks_Surface_Squeaks_Soft_Ext_SoundSet",
				"Tracks_Surface_Squeaks_Hard_Ext_SoundSet",
				"Tank_General_Collision_SoundSet"
			};
		};
	};
	class MBT_02_railgun_base_F: MBT_02_base_F
	{
		class Sounds
		{
			soundSetsExt[]=
			{
				"Railgun_01_Charge_Start_SoundSet",
				"Railgun_01_Charge_Stop_SoundSet",
				"Railgun_01_Charge_Loop_SoundSet",
				"MBT_02_Engine_RPM0_EXT_SoundSet",
				"MBT_02_Engine_RPM1_EXT_SoundSet",
				"MBT_02_Engine_RPM2_EXT_SoundSet",
				"MBT_02_Engine_RPM3_EXT_SoundSet",
				"MBT_02_Engine_EXT_Burst_SoundSet",
				"MBT_02_Tracks_01_EXT_SoundSet",
				"MBT_02_Tracks_02_EXT_SoundSet",
				"MBT_02_Tracks_03_EXT_SoundSet",
				"MBT_02_Tracks_04_EXT_SoundSet",
				"MBT_02_Tracks_05_EXT_SoundSet",
				"MBT_02_Tracks_06_EXT_SoundSet",
				"MBT_02_Rain_EXT_SoundSet",
				"MBT_02_Tracks_Brake_Hard_EXT_SoundSet",
				"MBT_02_Tracks_Brake_Soft_EXT_SoundSet",
				"MBT_02_Tracks_Turn_Hard_EXT_SoundSet",
				"MBT_02_Tracks_Turn_Soft_EXT_SoundSet",
				"MBT_02_Drive_Water_EXT_SoundSet",
				"MBT_02_Drive_Dirt_EXT_SoundSet",
				"MBT_02_Turbine01_Ext_Front_Tonal_SoundSet",
				"MBT_02_Turbine01_Ext_Rear_Tonal_SoundSet",
				"MBT_02_Turbine01_Ext_Front_Noisy_SoundSet",
				"MBT_02_Turbine01_Ext_Rear_Noisy_SoundSet",
				"MBT_02_Servo01_Ext_SoundSet",
				"MBT_02_Servo02_Ext_SoundSet",
				"Tracks_Movement_Dirt_Ext_01_SoundSet",
				"Tracks_Surface_Soft_Ext_SoundSet",
				"Tracks_Surface_Hard_Ext_SoundSet",
				"Tracks_Surface_Sand_Ext_SoundSet",
				"Tracks_Surface_Squeaks_Soft_Ext_SoundSet",
				"Tracks_Surface_Squeaks_Hard_Ext_SoundSet",
				"Tank_General_Collision_SoundSet"
			};
			soundSetsInt[]=
			{
				"Railgun_01_Charge_Start_SoundSet",
				"Railgun_01_Charge_Stop_SoundSet",
				"Railgun_01_Charge_Loop_SoundSet",
				"MBT_02_Engine_RPM0_INT_SoundSet",
				"MBT_02_Engine_RPM1_INT_SoundSet",
				"MBT_02_Engine_RPM2_INT_SoundSet",
				"MBT_02_Engine_RPM3_INT_SoundSet",
				"MBT_02_Engine_INT_Burst_SoundSet",
				"MBT_02_Tracks_01_INT_SoundSet",
				"MBT_02_Tracks_02_INT_SoundSet",
				"MBT_02_Tracks_03_INT_SoundSet",
				"MBT_02_Tracks_04_INT_SoundSet",
				"MBT_02_Tracks_05_INT_SoundSet",
				"MBT_02_Tracks_06_INT_SoundSet",
				"MBT_02_Interior_Tone_Engine_Off_SoundSet",
				"MBT_02_Interior_Tone_Engine_On_SoundSet",
				"MBT_02_Rattling_INT_SoundSet",
				"MBT_02_Rain_INT_SoundSet",
				"MBT_02_Tracks_Brake_Hard_INT_SoundSet",
				"MBT_02_Tracks_Brake_Soft_INT_SoundSet",
				"MBT_02_Tracks_Turn_Hard_INT_SoundSet",
				"MBT_02_Tracks_Turn_Soft_INT_SoundSet",
				"MBT_02_Drive_Water_INT_SoundSet",
				"MBT_02_Drive_Dirt_INT_SoundSet",
				"MBT_02_Turbine01_Int_Tonal_SoundSet",
				"MBT_02_Turbine01_Int_Noisy_SoundSet",
				"MBT_02_Servo01_Int_SoundSet",
				"MBT_02_Servo02_Int_SoundSet",
				"Tracks_Movement_Dirt_Int_01_SoundSet",
				"Tracks_Surface_Soft_Int_SoundSet",
				"Tracks_Surface_Hard_Int_SoundSet",
				"Tracks_Surface_Sand_Int_SoundSet",
				"Tracks_Surface_Squeaks_Soft_Int_SoundSet",
				"Tracks_Surface_Squeaks_Hard_Int_SoundSet",
				"Tanks_Material_Strain_Int_SoundSet",
				"Tank_General_Collision_Int_SoundSet"
			};
		};
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets;
	};
	class StaticMGWeapon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
			class ViewOptics;
		};
	};
	class HMG_02_base_F: StaticMGWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				optics=0;
				class ViewOptics: ViewOptics
				{
					visionMode[]={};
				};
			};
		};
	};
	class Truck_02_MRL_base_F: Truck_02_base_F
	{
		threat[]={0.69999999,0.5,0.30000001};
	};
};
class CfgAnimationSourceSounds
{
	class carrier_01_deflector
	{
		class carrier_01_deflectorUp
		{
			loop=0;
			terminate=0;
			trigger="direction";
			sound1[]=
			{
				"a3\sounds_f_jets\buildings\carrier\deflector_up_1",
				1.5,
				1,
				150
			};
			sound[]=
			{
				"sound1",
				1
			};
		};
		class carrier_01_deflectorDown
		{
			loop=0;
			terminate=0;
			trigger="(1-direction)";
			sound1[]=
			{
				"a3\sounds_f_jets\buildings\carrier\deflector_down_1",
				1.5,
				1,
				150
			};
			sound[]=
			{
				"sound1",
				1
			};
		};
	};
	class SmallBellSound
	{
		class RingTheBell
		{
			loop=0;
			terminate=0;
			trigger="direction";
			sound0[]=
			{
				"a3\Sounds_F_Enoch\Assets\Environment\SpotFx\Chapel\bell_chapel",
				0.69,
				1,
				300
			};
			sound[]=
			{
				"sound0",
				1
			};
		};
	};
	class TinyBellSound
	{
		class RingTheTinyBell
		{
			loop=0;
			terminate=0;
			trigger="direction";
			sound0[]=
			{
				"a3\Sounds_F_Enoch\Assets\Environment\SpotFx\Chapel\bell_chapel_tiny",
				1,
				1,
				250
			};
			sound[]=
			{
				"sound0",
				1
			};
		};
	};
};
class CfgSoundSets
{
	class Rain_Tent_Medium_Light_SoundSet;
	class Rain_Tent_Small_02_Light_SoundSet;
	class Rain_Tent_Small_01_Light_SoundSet;
	class Rain_Tent_Small_01_Sparse_SoundSet: Rain_Tent_Small_01_Light_SoundSet
	{
		volumeFactor=1.2;
		soundShaders[]=
		{
			"Rain_Tent_Small_01_Sparse_SoundShader"
		};
	};
	class Rain_Tent_Small_02_Sparse_SoundSet: Rain_Tent_Small_02_Light_SoundSet
	{
		volumeFactor=1.2;
		soundShaders[]=
		{
			"Rain_Tent_Small_02_Sparse_SoundShader"
		};
	};
	class Rain_Tent_Medium_Sparse_SoundSet: Rain_Tent_Medium_Light_SoundSet
	{
		volumeFactor=1.2;
		soundShaders[]=
		{
			"Rain_Tent_Medium_Sparse_SoundShader"
		};
	};
	class Rifle_silencerShot_Base_SoundSet;
	class Pistol_silencerShot_Base_SoundSet;
	class Rifle_silencerTail_Base_SoundSet;
	class Sfx_DeconShower_Center_01_SoundSet;
	class Rifle_Tail_Base_SoundSet;
	class footsteps_default_tactical_SoundSet;
	class footsteps_default_tactical_Exp_SoundSet;
	class footsteps_carpet_walk_Exp_SoundSet;
	class footsteps_carpet_run_Exp_SoundSet;
	class footsteps_carpet_sprint_Exp_SoundSet;
	class footsteps_carpet_crawl_Exp_SoundSet;
	class footsteps_concrete_walk_SoundSet;
	class footsteps_concrete_run_SoundSet;
	class footsteps_concrete_sprint_SoundSet;
	class footsteps_concrete_crawl_SoundSet;
	class footsteps_lino_walk_Exp_SoundSet;
	class footsteps_lino_run_Exp_SoundSet;
	class footsteps_lino_sprint_Exp_SoundSet;
	class footsteps_lino_crawl_Exp_SoundSet;
	class footsteps_mat_walk_Exp_SoundSet;
	class footsteps_mat_run_Exp_SoundSet;
	class footsteps_mat_sprint_Exp_SoundSet;
	class footsteps_mat_crawl_exp_SoundSet;
	class footsteps_MetalPlate_walk_SoundSet;
	class footsteps_MetalPlate_run_SoundSet;
	class footsteps_MetalPlate_sprint_SoundSet;
	class footsteps_MetalPlate_crawl_SoundSet;
	class footsteps_MetalPlate_walk_Exp_SoundSet;
	class footsteps_MetalPlate_run_Exp_SoundSet;
	class footsteps_MetalPlate_sprint_Exp_SoundSet;
	class footsteps_MetalPlate_crawl_Exp_SoundSet;
	class footsteps_pavement_walk_SoundSet;
	class footsteps_pavement_run_SoundSet;
	class footsteps_pavement_sprint_SoundSet;
	class footsteps_pavement_crawl_SoundSet;
	class footsteps_softwood_walk_SoundSet;
	class footsteps_softwood_run_SoundSet;
	class footsteps_softwood_sprint_SoundSet;
	class footsteps_softwood_crawl_SoundSet;
	class footsteps_softwood_walk_Exp_SoundSet;
	class footsteps_softwood_run_Exp_SoundSet;
	class footsteps_softwood_sprint_Exp_SoundSet;
	class footsteps_softwood_crawl_Exp_SoundSet;
	class footsteps_solidWood_walk_Exp_SoundSet;
	class footsteps_solidWood_run_Exp_SoundSet;
	class footsteps_solidWood_sprint_Exp_SoundSet;
	class footsteps_solidWood_crawl_Exp_SoundSet;
	class footsteps_carpet_int_walk_Exp_SoundSet: footsteps_carpet_walk_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_carpet_int_walk_LPF_Exp_SoundShader",
			"footsteps_carpet_int_walk_HPF_Exp_SoundShader",
			"footsteps_boots_soft_int_walk_Exp_SoundShader"
		};
		frequencyRandomizer=1.5;
		frequencyRandomizerMin=1;
	};
	class footsteps_carpet_int_tactical_Exp_SoundSet: footsteps_default_tactical_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_carpet_int_walk_LPF_Exp_SoundShader",
			"footsteps_carpet_int_walk_HPF_Exp_SoundShader",
			"footsteps_boots_soft_int_walk_Exp_SoundShader"
		};
		frequencyRandomizer=1.5;
		frequencyRandomizerMin=1;
	};
	class footsteps_carpet_int_run_Exp_SoundSet: footsteps_carpet_run_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_carpet_int_run_LPF_Exp_SoundShader",
			"footsteps_carpet_int_run_HPF_Exp_SoundShader",
			"footsteps_boots_soft_int_run_Exp_SoundShader"
		};
		frequencyRandomizer=1.5;
		frequencyRandomizerMin=1;
	};
	class footsteps_carpet_int_sprint_Exp_SoundSet: footsteps_carpet_sprint_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_carpet_int_sprint_LPF_Exp_SoundShader",
			"footsteps_carpet_int_sprint_HPF_Exp_SoundShader",
			"footsteps_boots_soft_int_sprint_Exp_SoundShader"
		};
		frequencyRandomizer=1.5;
		frequencyRandomizerMin=1;
	};
	class footsteps_carpet_int_crawl_Exp_SoundSet: footsteps_carpet_crawl_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_carpet_crawl_Exp_SoundShader",
			"footsteps_base_crawl_Exp_SoundShader"
		};
	};
	class footsteps_concrete_int_walk_SoundSet: footsteps_concrete_walk_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_concrete_int_walk_LPF_SoundShader",
			"footsteps_concrete_int_walk_HPF_SoundShader"
		};
		volumeFactor=1;
	};
	class footsteps_concrete_int_tactical_SoundSet: footsteps_default_tactical_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_concrete_int_walk_LPF_SoundShader",
			"footsteps_concrete_int_walk_HPF_SoundShader"
		};
		volumeFactor=1;
		frequencyRandomizer=3;
		frequencyRandomizerMin=1;
	};
	class footsteps_concrete_int_run_SoundSet: footsteps_concrete_run_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_concrete_int_run_LPF_SoundShader",
			"footsteps_concrete_int_run_HPF_SoundShader"
		};
		volumeFactor=1;
	};
	class footsteps_concrete_int_sprint_SoundSet: footsteps_concrete_sprint_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_concrete_int_sprint_LPF_SoundShader",
			"footsteps_concrete_int_sprint_HPF_SoundShader"
		};
		volumeFactor=1;
	};
	class footsteps_concrete_int_crawl_SoundSet: footsteps_concrete_crawl_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_concrete_int_crawl_SoundShader",
			"footsteps_base_crawl_SoundShader"
		};
		volumeFactor=1;
	};
	class footsteps_lino_int_walk_Exp_SoundSet: footsteps_lino_walk_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_lino_int_walk_Exp_SoundShader",
			"footsteps_boots_medium_int_walk_Exp_SoundShader"
		};
	};
	class footsteps_lino_int_tactical_Exp_SoundSet: footsteps_default_tactical_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_lino_int_walk_Exp_SoundShader",
			"footsteps_boots_medium_tactical_Exp_SoundShader"
		};
	};
	class footsteps_lino_int_run_Exp_SoundSet: footsteps_lino_run_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_lino_int_run_Exp_SoundShader",
			"footsteps_boots_medium_int_run_Exp_SoundShader"
		};
	};
	class footsteps_lino_int_sprint_Exp_SoundSet: footsteps_lino_sprint_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_lino_int_sprint_Exp_SoundShader",
			"footsteps_boots_medium_int_sprint_Exp_SoundShader"
		};
	};
	class footsteps_lino_int_crawl_Exp_SoundSet: footsteps_lino_crawl_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_lino_int_crawl_Exp_SoundShader",
			"footsteps_base_crawl_Exp_SoundShader"
		};
	};
	class footsteps_mat_int_walk_Exp_SoundSet: footsteps_mat_walk_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_mat_int_walk_Exp_SoundShader",
			"footsteps_boots_medium_int_walk_Exp_SoundShader"
		};
	};
	class footsteps_mat_int_tactical_Exp_SoundSet: footsteps_default_tactical_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_mat_int_walk_Exp_SoundShader",
			"footsteps_boots_medium_tactical_Exp_SoundShader"
		};
	};
	class footsteps_mat_int_run_Exp_SoundSet: footsteps_mat_run_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_mat_int_run_Exp_SoundShader",
			"footsteps_boots_medium_int_run_Exp_SoundShader"
		};
	};
	class footsteps_mat_int_sprint_Exp_SoundSet: footsteps_mat_sprint_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_mat_int_sprint_Exp_SoundShader",
			"footsteps_boots_medium_int_sprint_Exp_SoundShader"
		};
	};
	class footsteps_mat_int_crawl_exp_SoundSet: footsteps_mat_crawl_exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_mat_int_crawl_Exp_SoundShader",
			"footsteps_base_crawl_Exp_SoundShader"
		};
	};
	class footsteps_MetalPlate_int_walk_SoundSet: footsteps_MetalPlate_walk_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_MetalPlate_int_walk_SoundShader",
			"footsteps_boots_medium_int_walk_SoundShader"
		};
	};
	class footsteps_MetalPlate_int_tactical_SoundSet: footsteps_default_tactical_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_MetalPlate_int_walk_SoundShader",
			"footsteps_boots_medium_tactical_SoundShader"
		};
		frequencyRandomizer=0;
		frequencyRandomizerMin=0;
	};
	class footsteps_MetalPlate_int_run_SoundSet: footsteps_MetalPlate_run_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_MetalPlate_int_run_SoundShader",
			"footsteps_boots_medium_int_run_SoundShader"
		};
	};
	class footsteps_MetalPlate_int_sprint_SoundSet: footsteps_MetalPlate_sprint_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_MetalPlate_int_sprint_SoundShader",
			"footsteps_boots_medium_int_sprint_SoundShader"
		};
	};
	class footsteps_MetalPlate_int_crawl_SoundSet: footsteps_MetalPlate_crawl_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_MetalPlate_int_crawl_SoundShader",
			"footsteps_base_crawl_SoundShader"
		};
	};
	class footsteps_MetalPlate_int_walk_Exp_SoundSet: footsteps_MetalPlate_walk_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_MetalPlate_int_walk_Exp_SoundShader",
			"footsteps_boots_medium_int_walk_Exp_SoundShader"
		};
		frequencyRandomizer=0;
		frequencyRandomizerMin=0;
	};
	class footsteps_MetalPlate_int_tactical_Exp_SoundSet: footsteps_default_tactical_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_MetalPlate_int_walk_Exp_SoundShader",
			"footsteps_boots_medium_int_tactical_Exp_SoundShader"
		};
		frequencyRandomizer=0;
		frequencyRandomizerMin=0;
	};
	class footsteps_MetalPlate_int_run_Exp_SoundSet: footsteps_MetalPlate_run_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_MetalPlate_int_run_Exp_SoundShader",
			"footsteps_boots_medium_int_run_Exp_SoundShader"
		};
		frequencyRandomizer=0;
		frequencyRandomizerMin=0;
	};
	class footsteps_MetalPlate_int_sprint_Exp_SoundSet: footsteps_MetalPlate_sprint_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_MetalPlate_int_sprint_Exp_SoundShader",
			"footsteps_boots_medium_int_sprint_Exp_SoundShader"
		};
		frequencyRandomizer=0;
		frequencyRandomizerMin=0;
	};
	class footsteps_MetalPlate_int_crawl_Exp_SoundSet: footsteps_MetalPlate_crawl_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_metalPlate_int_crawl_SoundShader",
			"footsteps_base_crawl_Exp_SoundShader"
		};
	};
	class footsteps_pavement_int_walk_SoundSet: footsteps_pavement_walk_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_pavement_int_walk_SoundShader",
			"footsteps_boots_medium_int_walk_SoundShader"
		};
	};
	class footsteps_pavement_int_tactical_SoundSet: footsteps_default_tactical_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_pavement_int_walk_SoundShader",
			"footsteps_boots_medium_tactical_SoundShader"
		};
	};
	class footsteps_pavement_int_run_SoundSet: footsteps_pavement_run_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_pavement_int_run_SoundShader",
			"footsteps_boots_medium_int_run_SoundShader"
		};
	};
	class footsteps_pavement_int_sprint_SoundSet: footsteps_pavement_sprint_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_pavement_int_sprint_SoundShader",
			"footsteps_boots_medium_int_sprint_SoundShader"
		};
	};
	class footsteps_pavement_int_crawl_SoundSet: footsteps_pavement_crawl_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_pavement_int_crawl_SoundShader",
			"footsteps_base_crawl_SoundShader"
		};
	};
	class footsteps_softwood_int_walk_SoundSet: footsteps_softwood_walk_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_softwood_int_walk_SoundShader",
			"footsteps_boots_medium_int_walk_SoundShader",
			"footsteps_wood_creak_int_walk_SoundShader"
		};
	};
	class footsteps_softwood_int_tactical_SoundSet: footsteps_default_tactical_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_softwood_int_walk_SoundShader",
			"footsteps_boots_medium_tactical_SoundShader",
			"footsteps_wood_creak_int_walk_SoundShader"
		};
		frequencyRandomizer=0;
	};
	class footsteps_softwood_int_run_SoundSet: footsteps_softwood_run_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_softwood_int_run_SoundShader",
			"footsteps_boots_medium_int_run_SoundShader",
			"footsteps_wood_creak_int_run_SoundShader"
		};
	};
	class footsteps_softwood_int_sprint_SoundSet: footsteps_softwood_sprint_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_softwood_int_sprint_SoundShader",
			"footsteps_boots_medium_int_sprint_SoundShader",
			"footsteps_wood_creak_int_sprint_SoundShader"
		};
	};
	class footsteps_softwood_int_crawl_SoundSet: footsteps_softwood_crawl_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_softwood_int_crawl_SoundShader",
			"footsteps_base_crawl_SoundShader"
		};
	};
	class footsteps_softwood_int_walk_Exp_SoundSet: footsteps_softwood_walk_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_softwood_int_walk_Exp_SoundShader",
			"footsteps_boots_medium_int_walk_Exp_SoundShader",
			"footsteps_wood_creak_int_walk_Exp_SoundShader"
		};
		frequencyRandomizer=0;
	};
	class footsteps_softwood_int_tactical_Exp_SoundSet: footsteps_default_tactical_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_softwood_int_walk_Exp_SoundShader",
			"footsteps_boots_medium_tactical_Exp_SoundShader",
			"footsteps_wood_creak_int_walk_Exp_SoundShader"
		};
		frequencyRandomizer=0;
	};
	class footsteps_softwood_int_run_Exp_SoundSet: footsteps_softwood_run_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_softwood_int_run_Exp_SoundShader",
			"footsteps_boots_medium_int_run_Exp_SoundShader",
			"footsteps_wood_creak_int_run_Exp_SoundShader"
		};
		frequencyRandomizer=0;
	};
	class footsteps_softwood_int_sprint_Exp_SoundSet: footsteps_softwood_sprint_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_softwood_int_sprint_Exp_SoundShader",
			"footsteps_boots_medium_int_sprint_Exp_SoundShader",
			"footsteps_wood_creak_int_sprint_Exp_SoundShader"
		};
		frequencyRandomizer=0;
	};
	class footsteps_softwood_int_crawl_Exp_SoundSet: footsteps_softwood_crawl_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_softwood_int_crawl_Exp_SoundShader",
			"footsteps_base_crawl_Exp_SoundShader"
		};
	};
	class footsteps_solidWood_int_walk_Exp_SoundSet: footsteps_solidWood_walk_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_solidWood_int_walk_Exp_SoundShader",
			"footsteps_boots_medium_int_walk_Exp_SoundShader"
		};
		frequencyRandomizer=0;
	};
	class footsteps_solidWood_int_tactical_Exp_SoundSet: footsteps_default_tactical_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_solidWood_int_walk_Exp_SoundShader",
			"footsteps_boots_medium_tactical_Exp_SoundShader"
		};
		frequencyRandomizer=0;
	};
	class footsteps_solidWood_int_run_Exp_SoundSet: footsteps_solidWood_run_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_solidWood_int_run_Exp_SoundShader",
			"footsteps_boots_medium_int_run_Exp_SoundShader"
		};
		frequencyRandomizer=0;
	};
	class footsteps_solidWood_int_sprint_Exp_SoundSet: footsteps_solidWood_sprint_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_solidWood_int_sprint_Exp_SoundShader",
			"footsteps_boots_medium_int_sprint_Exp_SoundShader"
		};
		frequencyRandomizer=0;
	};
	class footsteps_solidWood_int_crawl_Exp_SoundSet: footsteps_solidWood_crawl_Exp_SoundSet
	{
		soundShaders[]=
		{
			"footsteps_solidWood_int_crawl_Exp_SoundShader",
			"footsteps_base_crawl_Exp_SoundShader"
		};
	};
	class Autocannon35mm_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class Autocannon30mmBody_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class Autocannon30mmTurret_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class Autocannon40mm_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class HMG050_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class HMG127mm_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class LMG65mmTurret_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class LMGCoax762mm_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class LMGMinigun65mm_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class M134Minigun_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class HMG127mm_static_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class MMG_SPMG_tail_SoundSet
	{
		frequencyRandomizer=1;
	};
	class Katiba_Tail_SoundSet: Rifle_Tail_Base_SoundSet
	{
		customCategory="";
	};
	class Mk20_Tail_SoundSet
	{
		customCategory="";
	};
	class Wind_Tree_Creacking_SoundSet
	{
		soundShaders[]=
		{
			"Wind_Tree_Creacking_SoundShader"
		};
		volumeRandomizer=2;
		volumeCurve="CreakAttenuationCurve";
		sound3DProcessingType="WindTreesCreaks_3DProcessingType";
		soundShadersLimit=1;
	};
	class Misc_Building_Sfx_SoundSet
	{
		soundShadersLimit=1;
	};
	class Misc_Building_Sfx_Globe_SoundSet: Misc_Building_Sfx_SoundSet
	{
		soundShaders[]=
		{
			"Misc_Building_Sfx_Globe_SoundShader"
		};
	};
	class VLS_01_Shot_SoundSet
	{
		sound3DProcessingType="ExplosionHeavy3DProcessingType";
	};
	class Insect_Day_SoundSet
	{
		volumeRandomizer=6;
		frequencyFactor=1;
		frequencyRandomizer=4;
		volumeCurve="insectsVolumeCurve";
		sound3DProcessingType="defaultShortPannerProcessingType";
	};
	class Insect_Night_SoundSet
	{
		volumeRandomizer=6;
		frequencyFactor=1;
		frequencyRandomizer=4;
		volumeCurve="insectsVolumeCurve";
		sound3DProcessingType="defaultShortPannerProcessingType";
	};
	class Insect_Day_Winged_SoundSet
	{
		volumeRandomizer=3;
		frequencyFactor=1;
		frequencyRandomizer=4;
		volumeCurve="insectsVolumeCurve";
		sound3DProcessingType="defaultShortPannerProcessingType";
	};
	class Crickets_Stratis_SingleA_Day_SoundSet
	{
		volumeRandomizer=6;
		frequencyRandomizer=2;
		volumeCurve="insectsVolumeCurve";
		sound3DProcessingType="defaultShortPannerProcessingType";
	};
	class Crickets_Stratis_GroupA_Day_SoundSet
	{
		volumeRandomizer=6;
		frequencyRandomizer=2;
		volumeCurve="insectsVolumeCurve";
		sound3DProcessingType="defaultShortPannerProcessingType";
	};
	class Crickets_Stratis_Night_SoundSet
	{
		volumeRandomizer=6;
		frequencyRandomizer=2;
		volumeCurve="insectsVolumeCurve";
		sound3DProcessingType="defaultShortPannerProcessingType";
	};
	class Wind_LeavesA_SoundSet
	{
		volumeRandomizer=2;
		frequencyFactor=1.1;
		frequencyRandomizer=4;
		volumeCurve="WindAttenuationCurve";
		sound3DProcessingType="WindPlantSmall3DProcessingType";
	};
	class Wind_LeavesA_Narrow_SoundSet
	{
		frequencyFactor=1;
		frequencyRandomizer=4;
		volumeCurve="WindAttenuationCurve";
		sound3DProcessingType="WindPlantSmall3DProcessingType";
	};
	class Wind_LeavesB_SoundSet
	{
		volumeRandomizer=2;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="WindAttenuationCurve";
		sound3DProcessingType="WindPlantMedium3DProcessingType";
	};
	class Wind_LeavesC_SoundSet
	{
		frequencyFactor=0.85000002;
		volumeRandomizer=2;
		frequencyRandomizer=4;
		volumeCurve="WindAttenuationCurve";
		sound3DProcessingType="WindPlantLarge3DProcessingType";
	};
	class Forest_Birds_All_Day_SoundSet
	{
		loop=0;
		volumeRandomizer=0.5;
		frequencyFactor=0.75;
		frequencyRandomizer=6;
		volumeCurve="birdsVolumeCurve";
		sound3DProcessingType="Birds3DProcessingType";
	};
	class Forest_Birds_All_Night_SoundSet
	{
		loop=0;
		volumeRandomizer=0.5;
		frequencyFactor=1;
		frequencyRandomizer=0.5;
		volumeCurve="birdsVolumeCurve";
		sound3DProcessingType="Birds3DProcessingType";
	};
	class Forest_Woodpecker_SoundSet
	{
		volumeCurve="birdsVolumeCurve";
		sound3DProcessingType="Birds3DProcessingType";
	};
	class Forest_Whippoorwhill_Night_Dawn_SoundSet
	{
		volumeCurve="birdsVolumeCurve";
		sound3DProcessingType="Birds3DProcessingType";
	};
	class Forest_Wrens_Forest_Day_SoundSet
	{
		volumeCurve="birdsVolumeCurve";
		sound3DProcessingType="Birds3DProcessingType";
	};
	class Deercall_Forest_Night_SoundSet
	{
		volumeCurve="defaultAnimalAttenuationCurve";
		sound3DProcessingType="animal3DProcessingType";
	};
	class Wolves_Night_SoundSet
	{
		volumeCurve="defaultAnimalAttenuationCurve";
		sound3DProcessingType="animal3DProcessingType";
	};
	class Meadows_Birds_Day_SoundSet
	{
		loop=0;
		volumeRandomizer=0.5;
		frequencyFactor=0.75;
		frequencyRandomizer=6;
		delay=6;
		delayRandomizer=1;
		volumeCurve="birdsVolumeCurve";
		sound3DProcessingType="Birds3DProcessingType";
	};
	class Forest_Birds_Night_SoundSet
	{
		loop=0;
		volumeRandomizer=0.5;
		frequencyFactor=1;
		frequencyRandomizer=0.5;
		volumeCurve="birdsVolumeCurve";
		sound3DProcessingType="Birds3DProcessingType";
	};
	class Forest_Birds_Day_SoundSet
	{
		loop=0;
		volumeRandomizer=0.5;
		frequencyFactor=0.75;
		frequencyRandomizer=6;
		delay=8;
		delayRandomizer=1;
		volumeCurve="birdsVolumeCurve";
		sound3DProcessingType="Birds3DProcessingType";
	};
	class Air_Condition_SoundSet
	{
		volumeCurve="InverseSquare1Curve";
		sound3DProcessingType="PLant3DProcessingType";
	};
	class Electric_Box_SoundSet
	{
		volumeCurve="InverseSquare1Curve";
		sound3DProcessingType="PLant3DProcessingType";
	};
	class Rain_Tree_Large_Leaves_Sparse_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantLarge3DProcessingType";
	};
	class Rain_Tree_Large_Leaves_Light_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantLarge3DProcessingType";
	};
	class Rain_Tree_Large_Leaves_Medium_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantLarge3DProcessingType";
	};
	class Rain_Tree_Large_Leaves_Heavy_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantLarge3DProcessingType";
	};
	class Rain_Tree_Small_Pines_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantSmall3DProcessingType";
	};
	class Rain_Tree_Medium_Pines_Sparse_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantMedium3DProcessingType";
	};
	class Rain_Tree_Medium_Pines_Light_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantMedium3DProcessingType";
	};
	class Rain_Tree_Medium_Pines_Medium_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantMedium3DProcessingType";
	};
	class Rain_Tree_Medium_Pines_Heavy_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantMedium3DProcessingType";
	};
	class Rain_PlantA_Light_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantSmall3DProcessingType";
	};
	class Rain_PlantA_Medium_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantSmall3DProcessingType";
	};
	class Rain_PlantA_Heavy_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantSmall3DProcessingType";
	};
	class Rain_Tree_Light_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantMedium3DProcessingType";
	};
	class Rain_Tree_Medium_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantMedium3DProcessingType";
	};
	class Rain_Tree_Heavy_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantMedium3DProcessingType";
	};
	class Rain_WideTree_Light_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantMedium3DProcessingType";
	};
	class Rain_WideTree_Medium_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantMedium3DProcessingType";
	};
	class Rain_WideTree_Heavy_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantMedium3DProcessingType";
	};
	class Rain_SmallTree_Light_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantSmall3DProcessingType";
	};
	class Rain_SmallTree_Medium_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantSmall3DProcessingType";
	};
	class Rain_SmallTree_Heavy_SoundSet
	{
		volumeRandomizer=1;
		frequencyFactor=1;
		frequencyRandomizer=2;
		volumeCurve="RainPlantsAttenuationCurve";
		sound3DProcessingType="RainPlantSmall3DProcessingType";
	};
	class RocketsLight_Shot_SoundSet
	{
		volumeRandomizer=0.5;
		frequencyRandomizer=0.5;
	};
	class RocketsMedium_Shot_SoundSet
	{
		volumeRandomizer=0.5;
		frequencyRandomizer=0.5;
	};
	class RocketsHeavy_Shot_SoundSet
	{
		volumeRandomizer=0.5;
		frequencyRandomizer=0.5;
	};
	class fx_DeconShower_Center_01_SoundSet: Sfx_DeconShower_Center_01_SoundSet
	{
	};
	class Railgun_01_Tail_SoundSet
	{
		soundShaders[]+=
		{
			"Railgun_01_Tail_SoundShader"
		};
	};
	class Shell19mm25mm_Exp_SoundSet
	{
		soundShaders[]+=
		{
			"Shell19mm25mm_midExp_SoundShader"
		};
	};
	class Tractor_01_Engine_INT_Burst_SoundSet
	{
		spatial=0;
	};
	class Lt_01_Engine_INT_Burst_SoundSet
	{
		spatial=0;
	};
	class MBT_01_Engine_INT_Burst_SoundSet
	{
		spatial=0;
	};
	class MBT_03_Engine_INT_Burst_SoundSet
	{
		spatial=0;
	};
	class MBT_04_Engine_INT_Burst_SoundSet
	{
		spatial=0;
	};
	class Mrap_01_Engine_INT_Burst_SoundSet
	{
		spatial=0;
	};
	class APC_Tracked_03_Engine_INT_Burst_SoundSet
	{
		spatial=0;
	};
	class Engine_Base_RPM0_EXT_SoundSet;
	class Engine_Base_RPM1_EXT_SoundSet;
	class Engine_Base_RPM2_EXT_SoundSet;
	class Engine_Base_RPM3_EXT_SoundSet;
	class Engine_Base_RPM0_INT_SoundSet;
	class Engine_Base_RPM1_INT_SoundSet;
	class Engine_Base_RPM2_INT_SoundSet;
	class Engine_Base_RPM3_INT_SoundSet;
	class MBT_02_Engine_EXT_Burst_SoundSet
	{
		soundShaders[]=
		{
			"MBT_02_Engine_EXT_Burst_SoundShader"
		};
		playTrigger="thrust * (speed factor[5,0.1]) * (1- thrust * ((speed factor[-2,0])))";
		posOffset[]={0,0,-4};
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		frequencyRandomizer=1;
		frequencyRandomizerMin=0;
		sound3DProcessingType="VehicleExt_3DProcessingType";
		volumeCurve="InverseSquare2Curve";
		occlusionFactor=0.5;
		obstructionFactor=0.30000001;
		volumeFactor=1;
		spatial=1;
		loop=0;
	};
	class MBT_02_Engine_INT_Burst_SoundSet
	{
		soundShaders[]=
		{
			"MBT_02_Engine_INT_Burst_SoundShader"
		};
		playTrigger="thrust * (speed factor[5,0.1]) * (1- thrust * ((speed factor[-2,0])))";
		posOffset[]={0,0,0};
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		frequencyRandomizer=1;
		frequencyRandomizerMin=0;
		sound3DProcessingType="VehicleInt_Back_3DProcessingType";
		volumeCurve="InverseSquare2Curve";
		volumeFactor=1;
		spatial=0;
		loop=0;
	};
	class MBT_02_Engine_RPM0_INT_SoundSet: Engine_Base_RPM0_INT_SoundSet
	{
		soundShaders[]=
		{
			"MBT_02_Engine_RPM0_INT_SoundShader"
		};
		sound3DProcessingType="VehicleInt_Back_3DProcessingType";
		posOffset[]={0,0,0};
		volumeFactor=1;
	};
	class MBT_02_Engine_RPM1_INT_SoundSet: Engine_Base_RPM0_INT_SoundSet
	{
		soundShaders[]=
		{
			"MBT_02_Engine_RPM1_INT_SoundShader"
		};
		sound3DProcessingType="VehicleInt_Back_3DProcessingType";
		posOffset[]={0,0,0};
		volumeFactor=1.5;
	};
	class MBT_02_Engine_RPM2_INT_SoundSet: Engine_Base_RPM0_INT_SoundSet
	{
		soundShaders[]=
		{
			"MBT_02_Engine_RPM2_INT_SoundShader"
		};
		sound3DProcessingType="VehicleInt_Back_3DProcessingType";
		posOffset[]={0,0,0};
		volumeFactor=2;
	};
	class MBT_02_Engine_RPM3_INT_SoundSet: Engine_Base_RPM0_INT_SoundSet
	{
		soundShaders[]=
		{
			"MBT_02_Engine_RPM3_INT_SoundShader"
		};
		sound3DProcessingType="VehicleInt_Back_3DProcessingType";
		posOffset[]={0,0,0};
		volumeFactor=2.5;
	};
	class MBT_02_Engine_RPM0_EXT_SoundSet: Engine_Base_RPM0_EXT_SoundSet
	{
		soundShaders[]=
		{
			"MBT_02_Engine_RPM0_EXT_SoundShader"
		};
		volumeFactor=1.2;
		sound3DProcessingType="VehicleExt_Engine_3DProcessingType";
		volumeCurve="InverseSquare2Curve";
		posOffset[]={0,0,-4};
	};
	class MBT_02_Engine_RPM1_EXT_SoundSet: Engine_Base_RPM0_EXT_SoundSet
	{
		soundShaders[]=
		{
			"MBT_02_Engine_RPM1_EXT_SoundShader"
		};
		volumeFactor=1.25;
		sound3DProcessingType="VehicleExt_Engine_3DProcessingType";
		volumeCurve="InverseSquare2Curve";
		posOffset[]={0,0,-4};
	};
	class MBT_02_Engine_RPM2_EXT_SoundSet: Engine_Base_RPM0_EXT_SoundSet
	{
		soundShaders[]=
		{
			"MBT_02_Engine_RPM2_EXT_SoundShader"
		};
		volumeFactor=1.3;
		sound3DProcessingType="VehicleExt_Engine_3DProcessingType";
		volumeCurve="InverseSquare2Curve";
		posOffset[]={0,0,-4};
	};
	class MBT_02_Engine_RPM3_EXT_SoundSet: Engine_Base_RPM0_EXT_SoundSet
	{
		soundShaders[]=
		{
			"MBT_02_Engine_RPM3_EXT_SoundShader"
		};
		volumeFactor=1.35;
		sound3DProcessingType="VehicleExt_Engine_3DProcessingType";
		volumeCurve="InverseSquare2Curve";
		posOffset[]={0,0,-4};
	};
	class Forest_Meadow_Edge_Birds_Bg_Day_Soundset
	{
		sound3DProcessingType="";
	};
	class Silence_Bg_Day_01_SoundSet
	{
		sound3DProcessingType="";
	};
	class Silence_Bg_Night_01_SoundSet
	{
		sound3DProcessingType="";
	};
	class Wind_Heavy_Filler_SoundSet
	{
		sound3DProcessingType="Wind_Heavy_Filler_3DProcessingType";
	};
	class Wind_Filler_SoundSet
	{
		sound3DProcessingType="Wind_Heavy_Filler_3DProcessingType";
	};
	class Forest_GrassWispyBreeze_01_SoundSet
	{
		sound3DProcessingType="";
	};
	class WindForest_Low_Enoch_SoundSet
	{
		sound3DProcessingType="";
	};
	class Wind_Forest_Heavy_SoundSet
	{
		sound3DProcessingType="";
	};
	class Rain_Bg_Light_Sparse_SoundSet
	{
		sound3DProcessingType="";
	};
	class Rain_Bg_Forest_Light_SoundSet
	{
		sound3DProcessingType="";
	};
	class Rain_Bg_Forest_Low_SoundSet
	{
		sound3DProcessingType="";
	};
	class Rain_Bg_Forest_Medium_SoundSet
	{
		sound3DProcessingType="";
	};
	class Rain_Bg_Forest_Heavy_SoundSet
	{
		sound3DProcessingType="";
	};
	class Rain_Bg_Forest_Heavy_01_SoundSet
	{
		sound3DProcessingType="";
	};
	class Rain_Bg_Meadow_Heavy_01_SoundSet
	{
		sound3DProcessingType="";
	};
	class Msbs65_01_silencerTail_SoundSet: Rifle_silencerTail_Base_SoundSet
	{
		soundShaders[]=
		{
			"Msbs65_01_Tail_Silencer_Trees_SoundShader",
			"Msbs65_01_Tail_Silencer_Forest_SoundShader",
			"Msbs65_01_Tail_Silencer_Meadows_SoundShader",
			"Msbs65_01_Tail_Silencer_Houses_SoundShader"
		};
	};
	class Sfx_Dog_SoundSet
	{
		soundShaders[]=
		{
			"Sfx_Dog_SoundShader"
		};
		volumeFactor=1;
		volumeCurve="InverseSquare2Curve";
		spatial=1;
		doppler=0;
		speedOfSound=1;
		loop=0;
		sound3DProcessingType="SpotFx3DProcessingType";
		occlusionFactor=0.5;
		obstructionFactor=0.30000001;
	};
	class Sfx_Dog_Distant_SoundSet
	{
		soundShaders[]=
		{
			"Sfx_Dog_Distant_SoundShader"
		};
		volumeFactor=2;
		volumeCurve="InverseSquare2Curve";
		spatial=1;
		doppler=0;
		speedOfSound=1;
		loop=0;
		sound3DProcessingType="SpotFx3DProcessingType";
		distanceFilter="LowIntensityDistanceFilter";
		occlusionFactor=0.5;
		obstructionFactor=0.30000001;
	};
};
class CfgSoundShaders
{
	class Wind_Wood_Tension_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_01",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_02",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_03",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_04",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_05",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_06",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_07",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_08",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_09",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_10",
				1
			}
		};
		volume="(wind factor[0.4, 0.8])";
		range=50;
	};
	class Wind_Wood_Tension_Dry_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Light_01",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Light_02",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Light_03",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Light_04",
				1
			}
		};
		volume="(wind factor[0.4, 0.8])";
		range=40;
	};
	class Wind_Wood_Tension_Heavy_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Low_01",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Low_02",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Low_03",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Low_04",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Low_05",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Low_06",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Low_07",
				1
			}
		};
		volume="(wind factor[0.4, 0.8])";
		range=50;
	};
	class Wind_Gate_Wood_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Whistle_01",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Whistle_02",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Whistle_03",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Whistle_04",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Whistle_05",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Whistle_06",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Whistle_07",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Whistle_08",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Whistle_09",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Creak_Whistle_10",
				1
			}
		};
		volume="(wind factor[0.3, 0.8])";
		range=50;
	};
	class Wind_Wood_Window_Tension_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Window_Creak_01",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Window_Creak_02",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Window_Creak_03",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Window_Creak_04",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Window_Creak_05",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Window_Creak_06",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Wood_Window_Creak_07",
				1
			}
		};
		volume="1.5 * (wind factor[0.45, 0.8])";
	};
	class Rain_Tree_Large_Leaves_Sparse_SoundShader
	{
		volume="1 * raindrops *  (rain factor[0,0.1])*(rain factor[0.4,0.2])";
	};
	class Rain_Tree_Large_Leaves_Light_SoundShader
	{
		volume="0.5 * raindrops * (rain factor [0.1, 0.25]) * (rain factor [0.4, 0.3])";
	};
	class Rain_Tree_Large_Leaves_Medium_SoundShader
	{
		volume="0.5*raindrops *  (rain factor[0.2,0.4])*(rain factor[0.8,0.7])";
	};
	class Rain_Tree_Large_Leaves_Heavy_SoundShader
	{
		volume="0.8* raindrops *  (rain factor[0.8, 0.95])";
	};
	class Rain_Tree_Small_Pines_SoundShader
	{
		volume="raindrops * rain";
	};
	class Rain_Tree_Medium_Pines_Sparse_SoundShader
	{
		volume="0.5 * raindrops *  (rain factor[0,0.1])*(rain factor[0.4,0.2])";
	};
	class Rain_Tree_Medium_Pines_Light_SoundShader
	{
		volume="0.1 * raindrops * (rain factor [0.1, 0.25]) * (rain factor [0.4, 0.3])";
	};
	class Rain_Tree_Medium_Pines_Medium_SoundShader
	{
		volume="0.1 * raindrops *  (rain factor[0.2,0.4])*(rain factor[0.8,0.7])";
	};
	class Rain_Tree_Medium_Pines_Heavy_SoundShader
	{
		volume="0.1 * raindrops *  (rain factor[0.8, 0.95])";
	};
	class Rain_Tent_Small_01_Sparse_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Rain\Tents\rain_tent_sparse_01",
				1
			}
		};
		volume="raindrops *  (rain factor[0,0.1])*(rain factor[0.4,0.2])";
		range=14;
	};
	class Rain_Tent_Small_01_Light_SoundShader
	{
		volume="raindrops *  (rain factor [0.1, 0.25]) * (rain factor [0.4, 0.3])";
	};
	class Rain_Tent_Small_01_Medium_SoundShader
	{
		volume="raindrops *  (rain factor[0.2,0.4])*(rain factor[0.8,0.7])";
	};
	class Rain_Tent_Small_01_Heavy_SoundShader
	{
		volume="raindrops *  (rain factor[0.8, 0.95])";
	};
	class Rain_Tent_Small_02_Sparse_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Rain\Tents\rain_tent_sparse_01",
				1
			}
		};
		volume="raindrops *  (rain factor[0,0.1])*(rain factor[0.4,0.2])";
		range=14;
	};
	class Rain_Tent_Small_02_Light_SoundShader
	{
		volume="raindrops *  (rain factor [0.1, 0.25]) * (rain factor [0.4, 0.3])";
	};
	class Rain_Tent_Small_02_Medium_SoundShader
	{
		volume="raindrops *  (rain factor[0.2,0.4])*(rain factor[0.8,0.7])";
	};
	class Rain_Tent_Small_02_Heavy_SoundShader
	{
		volume="raindrops *  (rain factor[0.8, 0.95])";
	};
	class Rain_Tent_Medium_Sparse_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Rain\Tents\rain_tent_sparse_01",
				1
			}
		};
		volume="raindrops *  (rain factor[0,0.1])*(rain factor[0.4,0.2])";
		range=14;
	};
	class Rain_Tent_Medium_Light_SoundShader
	{
		volume="raindrops *  (rain factor [0.1, 0.25]) * (rain factor [0.4, 0.3])";
	};
	class Rain_Tent_Medium_Medium_SoundShader
	{
		volume="raindrops *  (rain factor[0.2,0.4])*(rain factor[0.8,0.7])";
	};
	class Rain_Tent_Medium_Heavy_SoundShader
	{
		volume="raindrops *  (rain factor[0.8, 0.95])";
	};
	class Forest_Bg_Night_01_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\Backgrounds\Forest\Forest_Bg_Noon",
				1
			}
		};
		volume=0;
	};
	class Sfx_Dog_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f\ambient\animals\dog1",
				1
			},
			{
				"a3\sounds_f\ambient\animals\dog2",
				1
			},
			{
				"a3\sounds_f\ambient\animals\dog3",
				1
			}
		};
		volume=1.2;
		range=100;
		rangeCurve[]=
		{
			{0,1},
			{50,1},
			{100,0}
		};
	};
	class Sfx_Dog_Distant_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\distant\sfx001",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\distant\sfx002",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\distant\sfx003",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\distant\sfx004",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\distant\sfx005",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\distant\sfx006",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\distant\sfx007",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\distant\sfx008",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\distant\sfx009",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\distant\sfx010",
				1
			}
		};
		volume=1.3;
		range=400;
		rangeCurve[]=
		{
			{0,0},
			{50,0},
			{75,0.69999999},
			{100,0.60000002},
			{150,0.5},
			{200,0.40000001},
			{250,0.30000001},
			{300,0.2},
			{350,0.1}
		};
	};
	class Night_Trills_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Atmos\Trill_01",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Atmos\Trill_02",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Atmos\Trill_03",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Atmos\Trill_04",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Atmos\Trill_05",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Atmos\Trill_06",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Atmos\Trill_07",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Atmos\Trill_08",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Atmos\Trill_09",
				1
			}
		};
	};
	class Misc_Building_Sfx_SoundShader;
	class footsteps_default_walk_SoundShader;
	class footsteps_default_run_SoundShader;
	class footsteps_default_sprint_SoundShader;
	class footsteps_default_crawl_SoundShader;
	class footsteps_default_walk_Exp_SoundShader;
	class footsteps_default_tactical_Exp_SoundShader;
	class footsteps_default_run_Exp_SoundShader;
	class footsteps_default_sprint_Exp_SoundShader;
	class footsteps_default_crawl_Exp_SoundShader;
	class footsteps_concrete_int_walk_LPF_SoundShader: footsteps_default_walk_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_LPF_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_LPF_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_LPF_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_LPF_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_LPF_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_LPF_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_LPF_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_LPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_concrete_int_walk_HPF_SoundShader: footsteps_default_walk_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_HPF_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_HPF_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_HPF_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_HPF_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_HPF_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_HPF_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_HPF_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_walk_HPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_concrete_int_run_LPF_SoundShader: footsteps_default_run_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_LPF_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_LPF_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_LPF_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_LPF_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_LPF_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_LPF_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_LPF_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_LPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_concrete_int_run_HPF_SoundShader: footsteps_default_run_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_HPF_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_HPF_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_HPF_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_HPF_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_HPF_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_HPF_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_HPF_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_run_HPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_concrete_int_sprint_LPF_SoundShader: footsteps_default_sprint_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_LPF_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_LPF_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_LPF_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_LPF_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_LPF_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_LPF_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_LPF_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_LPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_concrete_int_sprint_HPF_SoundShader: footsteps_default_sprint_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_HPF_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_HPF_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_HPF_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_HPF_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_HPF_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_HPF_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_HPF_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_concrete\concrete_int_sprint_HPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_concrete_int_crawl_SoundShader: footsteps_default_crawl_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\crawl\concrete_int_crawl_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\concrete_int_crawl_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\concrete_int_crawl_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\concrete_int_crawl_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\concrete_int_crawl_5",
				1
			}
		};
		frequency=1;
	};
	class footsteps_mat_int_walk_Exp_SoundShader: footsteps_default_walk_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_walk_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_walk_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_walk_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_walk_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_walk_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_walk_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_walk_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_walk_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_mat_int_run_Exp_SoundShader: footsteps_default_run_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_run_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_run_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_run_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_run_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_run_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_run_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_run_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_run_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_mat_int_sprint_Exp_SoundShader: footsteps_default_sprint_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_sprint_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_sprint_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_sprint_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_sprint_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_sprint_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_sprint_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_sprint_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_mat_exp\mat_int_sprint_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_mat_int_crawl_Exp_SoundShader: footsteps_default_crawl_Exp_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_exp\characters\crawl\mat_int_crawl_1",
				1
			},
			{
				"a3\sounds_f_exp\characters\crawl\mat_int_crawl_2",
				1
			},
			{
				"a3\sounds_f_exp\characters\crawl\mat_int_crawl_3",
				1
			},
			{
				"a3\sounds_f_exp\characters\crawl\mat_int_crawl_4",
				1
			},
			{
				"a3\sounds_f_exp\characters\crawl\mat_int_crawl_5",
				1
			}
		};
		volume=0.12589253;
		frequency=1;
	};
	class footsteps_lino_int_walk_Exp_SoundShader: footsteps_default_walk_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_lino_tactical_Exp_SoundShader: footsteps_default_tactical_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_walk_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_lino_int_run_Exp_SoundShader: footsteps_default_run_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_run_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_run_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_run_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_run_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_run_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_run_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_run_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_run_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_lino_int_sprint_Exp_SoundShader: footsteps_default_sprint_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_sprint_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_sprint_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_sprint_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_sprint_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_sprint_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_sprint_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_sprint_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_lino_exp\lino_int_sprint_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_lino_int_crawl_Exp_SoundShader: footsteps_default_crawl_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\crawl\lino_int_crawl_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\lino_int_crawl_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\lino_int_crawl_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\lino_int_crawl_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\lino_int_crawl_5",
				1
			}
		};
		frequency=1;
	};
	class footsteps_MetalPlate_int_walk_SoundShader: footsteps_default_walk_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_walk_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_walk_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_walk_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_walk_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_walk_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_walk_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_walk_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_walk_8",
				1
			}
		};
		volume=0.89125091;
		frequency=1;
	};
	class footsteps_MetalPlate_int_run_SoundShader: footsteps_default_run_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_run_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_run_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_run_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_run_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_run_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_run_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_run_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_run_8",
				1
			}
		};
		volume=1;
		frequency=1;
	};
	class footsteps_MetalPlate_int_sprint_SoundShader: footsteps_default_sprint_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_sprint_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_sprint_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_sprint_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_sprint_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_sprint_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_sprint_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_sprint_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_MetalPlate\MetalPlate_sprint_8",
				1
			}
		};
		volume=1;
		frequency=1;
	};
	class footsteps_metalPlate_int_crawl_SoundShader: footsteps_default_crawl_SoundShader
	{
		samples[]=
		{
			{
				"\a3\sounds_f_exp\characters\crawl\metalplate_int_crawl_1",
				1
			},
			{
				"\a3\sounds_f_exp\characters\crawl\metalplate_int_crawl_2",
				1
			},
			{
				"\a3\sounds_f_exp\characters\crawl\metalplate_int_crawl_3",
				1
			},
			{
				"\a3\sounds_f_exp\characters\crawl\metalplate_int_crawl_4",
				1
			},
			{
				"\a3\sounds_f_exp\characters\crawl\metalplate_int_crawl_5",
				1
			}
		};
		volume=0.12589253;
		frequency=1;
	};
	class footsteps_MetalPlate_int_walk_Exp_SoundShader: footsteps_default_walk_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_walk_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_walk_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_walk_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_walk_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_walk_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_walk_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_walk_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_walk_8",
				1
			}
		};
		volume=0.89125091;
		frequency=1;
	};
	class footsteps_MetalPlate_int_run_Exp_SoundShader: footsteps_default_run_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_run_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_run_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_run_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_run_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_run_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_run_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_run_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_run_8",
				1
			}
		};
		volume=1;
		frequency=1;
	};
	class footsteps_MetalPlate_int_sprint_Exp_SoundShader: footsteps_default_sprint_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_sprint_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_sprint_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_sprint_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_sprint_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_sprint_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_sprint_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_sprint_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_metalplate_exp\MetalPlate_sprint_8",
				1
			}
		};
		volume=1;
		frequency=1;
	};
	class footsteps_pavement_int_walk_SoundShader: footsteps_default_walk_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_walk_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_walk_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_walk_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_walk_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_walk_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_walk_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_walk_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_walk_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_pavement_int_run_SoundShader: footsteps_default_run_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_run_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_run_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_run_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_run_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_run_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_run_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_run_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_run_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_pavement_int_sprint_SoundShader: footsteps_default_sprint_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_sprint_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_sprint_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_sprint_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_sprint_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_sprint_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_sprint_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_sprint_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_pavement\pavement_int_sprint_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_pavement_int_crawl_SoundShader: footsteps_default_crawl_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\crawl\pavement_int_crawl_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\pavement_int_crawl_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\pavement_int_crawl_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\pavement_int_crawl_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\crawl\pavement_int_crawl_5",
				1
			}
		};
		frequency=1;
	};
	class footsteps_softwood_int_walk_SoundShader: footsteps_default_walk_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_walk_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_walk_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_walk_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_walk_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_walk_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_walk_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_walk_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_walk_8",
				1
			}
		};
		volume=0.3548134;
		frequency=1;
	};
	class footsteps_softwood_int_run_SoundShader: footsteps_default_run_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_run_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_run_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_run_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_run_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_run_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_run_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_run_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_run_8",
				1
			}
		};
		volume=0.63095737;
		frequency=1;
	};
	class footsteps_softwood_int_sprint_SoundShader: footsteps_default_sprint_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_sprint_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_sprint_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_sprint_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_sprint_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_sprint_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_sprint_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_sprint_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_sprint_8",
				1
			}
		};
		volume=0.70794576;
		frequency=1;
	};
	class footsteps_softwood_int_crawl_SoundShader: footsteps_default_crawl_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_crawl_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_crawl_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_crawl_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_crawl_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\int_softwood\softwood_int_crawl_5",
				1
			}
		};
		volume=0.12589253;
		frequency=1;
	};
	class footsteps_softwood_int_walk_Exp_SoundShader: footsteps_default_walk_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_8",
				1
			}
		};
		volume=0.56234133;
		frequency=1;
	};
	class footsteps_softwood_tactical_Exp_SoundShader: footsteps_default_tactical_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_walk_8",
				1
			}
		};
		volume=0.63095737;
		frequency=1;
	};
	class footsteps_softwood_int_run_Exp_SoundShader: footsteps_default_run_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_run_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_run_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_run_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_run_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_run_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_run_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_run_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_run_8",
				1
			}
		};
		volume=0.70794576;
		frequency=1;
	};
	class footsteps_softwood_int_sprint_Exp_SoundShader: footsteps_default_sprint_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_sprint_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_sprint_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_sprint_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_sprint_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_sprint_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_sprint_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_sprint_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_sprint_8",
				1
			}
		};
		volume=0.79432821;
		frequency=1;
	};
	class footsteps_softwood_int_crawl_Exp_SoundShader: footsteps_default_crawl_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_crawl_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_crawl_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_crawl_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_crawl_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_softwood_exp\softwood_int_crawl_5",
				1
			}
		};
		volume=0.12589253;
		frequency=1;
	};
	class footsteps_solidWood_int_walk_Exp_SoundShader: footsteps_default_walk_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_8",
				1
			}
		};
		volume=0.3548134;
		frequency=1;
	};
	class footsteps_solidWood_tactical_Exp_SoundShader: footsteps_default_tactical_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_walk_8",
				1
			}
		};
		volume=0.50118721;
		frequency=1;
	};
	class footsteps_solidWood_int_run_Exp_SoundShader: footsteps_default_run_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_run_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_run_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_run_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_run_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_run_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_run_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_run_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_run_8",
				1
			}
		};
		volume=0.70794576;
		frequency=1;
	};
	class footsteps_solidWood_int_sprint_Exp_SoundShader: footsteps_default_sprint_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_sprint_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_sprint_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_sprint_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_sprint_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_sprint_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_sprint_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_sprint_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_solidwood_exp\solidwood_int_sprint_8",
				1
			}
		};
		volume=0.79432821;
		frequency=1;
	};
	class footsteps_solidWood_int_crawl_Exp_SoundShader: footsteps_default_sprint_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\a3\sounds_f_exp\characters\crawl\solidwood_int_crawl_1",
				1
			},
			{
				"\a3\sounds_f_exp\characters\crawl\solidwood_int_crawl_2",
				1
			},
			{
				"\a3\sounds_f_exp\characters\crawl\solidwood_int_crawl_3",
				1
			},
			{
				"\a3\sounds_f_exp\characters\crawl\solidwood_int_crawl_4",
				1
			},
			{
				"\a3\sounds_f_exp\characters\crawl\solidwood_int_crawl_5",
				1
			}
		};
		volume=0.79432821;
		frequency=1;
	};
	class footsteps_carpet_int_walk_LPF_exp_SoundShader: footsteps_default_walk_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_LPF_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_LPF_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_LPF_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_LPF_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_LPF_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_LPF_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_LPF_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_LPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_carpet_int_walk_HPF_exp_SoundShader: footsteps_default_walk_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_HPF_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_HPF_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_HPF_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_HPF_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_HPF_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_HPF_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_HPF_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_walk_HPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_carpet_int_run_LPF_exp_SoundShader: footsteps_default_run_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_LPF_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_LPF_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_LPF_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_LPF_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_LPF_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_LPF_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_LPF_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_LPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_carpet_int_run_HPF_exp_SoundShader: footsteps_default_run_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_HPF_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_HPF_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_HPF_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_HPF_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_HPF_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_HPF_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_HPF_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_run_HPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_carpet_int_sprint_LPF_exp_SoundShader: footsteps_default_sprint_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_LPF_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_LPF_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_LPF_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_LPF_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_LPF_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_LPF_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_LPF_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_LPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_carpet_int_sprint_HPF_exp_SoundShader: footsteps_default_sprint_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_HPF_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_HPF_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_HPF_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_HPF_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_HPF_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_HPF_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_HPF_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_sprint_HPF_8",
				1
			}
		};
		frequency=1;
	};
	class footsteps_carpet_int_crawl_exp_SoundShader: footsteps_default_crawl_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_crawl_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_crawl_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_crawl_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_crawl_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\int_carpet_exp\carpet_int_crawl_5",
				1
			}
		};
		frequency=1;
	};
	class footsteps_wood_creak_int_walk_SoundShader: footsteps_default_walk_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_8",
				1
			},
			{
				"\A3\Sounds_F\dummysound",
				60
			},
			{
				"\A3\Sounds_F\dummysound",
				1
			}
		};
		volume=0.31622776;
		frequency=1;
	};
	class footsteps_wood_creak_int_run_SoundShader: footsteps_default_run_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_8",
				1
			},
			{
				"\A3\Sounds_F\dummysound",
				60
			},
			{
				"\A3\Sounds_F\dummysound",
				1
			}
		};
		volume=0.31622776;
		frequency=1;
	};
	class footsteps_wood_creak_int_sprint_SoundShader: footsteps_default_sprint_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_1",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_2",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_3",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_4",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_5",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_6",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_7",
				1
			},
			{
				"\A3\sounds_f\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_8",
				1
			},
			{
				"\A3\Sounds_F\dummysound",
				60
			},
			{
				"\A3\Sounds_F\dummysound",
				1
			}
		};
		volume=0.31622776;
		frequency=1;
	};
	class footsteps_wood_creak_int_walk_Exp_SoundShader: footsteps_default_walk_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_walk_8",
				1
			},
			{
				"\A3\Sounds_F\dummysound",
				60
			},
			{
				"\A3\Sounds_F\dummysound",
				1
			}
		};
		volume=0.31622776;
		frequency=1;
	};
	class footsteps_wood_creak_int_run_Exp_SoundShader: footsteps_default_run_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_run_8",
				1
			},
			{
				"\A3\Sounds_F\dummysound",
				60
			},
			{
				"\A3\Sounds_F\dummysound",
				1
			}
		};
		volume=0.31622776;
		frequency=1;
	};
	class footsteps_wood_creak_int_sprint_Exp_SoundShader: footsteps_default_sprint_Exp_SoundShader
	{
		samples[]=
		{
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_1",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_2",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_3",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_4",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_5",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_6",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_7",
				1
			},
			{
				"\A3\sounds_f_exp\characters\footsteps\_additionals\int_wood_creaks\wood_creak_int_sprint_8",
				1
			},
			{
				"\A3\Sounds_F\dummysound",
				60
			},
			{
				"\A3\Sounds_F\dummysound",
				1
			}
		};
		volume=0.31622776;
		frequency=1;
	};
	class Crickets_Stratis_Night_SoundShader
	{
		samples[]+=
		{
			{
				"A3\Sounds_F_Exp\environment\animals\insect\insect_night_01",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\animals\insect\insect_night_02",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\animals\insect\insect_night_03",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\animals\insect\insect_night_04",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\animals\insect\insect_night_05",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\animals\insect\insect_night_06",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\animals\insect\insect_night_07",
				1
			}
		};
	};
	class Crickets_Stratis_SingleA_Day_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\environment\animals\insect\redesigned\crickets_single01",
				1
			},
			{
				"A3\Sounds_F\environment\animals\insect\redesigned\crickets_single02",
				1
			},
			{
				"a3\sounds_f\environment\animals\insect\cricket1",
				1
			},
			{
				"a3\sounds_f\environment\animals\insect\cricket2",
				1
			},
			{
				"a3\sounds_f\environment\animals\insect\cricket3",
				1
			},
			{
				"a3\sounds_f\environment\animals\insect\cricket4",
				1
			}
		};
	};
	class Rain_PlantB_Heavy_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Exp\environment\elements\rains\rain_PlantB_heavy_001",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\elements\rains\rain_PlantB_heavy_002",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\elements\rains\rain_PlantB_heavy_003",
				1
			}
		};
	};
	class Rain_PlantB_Medium_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Exp\environment\elements\rains\rain_PlantB_medium_001",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\elements\rains\rain_PlantB_medium_002",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\elements\rains\rain_PlantB_medium_003",
				1
			}
		};
	};
	class WindMeadows_Low_Enoch_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\Backgrounds\Wind\wind_meadows_light",
				1
			}
		};
	};
	class ForestAfternoon_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Exp\Environment\ambient\forest\forest_afternoon",
				1
			}
		};
		volume="(altitudeGround factor [100,30]) * (altitudeGround factor [100,30]) * (daytime factor [0.46, 0.54]) * (daytime factor [0.83, 0.75])";
	};
	class Ambient_AircraftCarrier_DeckBridge_Interior_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_jets\buildings\carrier\deck_bridge_interior_area",
				1
			}
		};
		volume="interior";
		range=50;
	};
	class Shell105mm130mm_closeExp_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f\arsenal\explosives\shells\shellmedium_closeexp_01",
				1
			},
			{
				"a3\sounds_f\arsenal\explosives\shells\shellmedium_closeexp_02",
				1
			},
			{
				"a3\sounds_f\arsenal\explosives\shells\shellmedium_closeexp_03",
				1
			},
			{
				"a3\sounds_f\arsenal\explosives\shells\shellmedium_closeexp_04",
				1
			}
		};
		volume=1;
		range=90;
		rangeCurve="CannonCloseShotCurve";
	};
	class Shell155mm_closeExp_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f\arsenal\explosives\shells\shellheavy_closeexp",
				1
			}
		};
		volume=1;
		range=110;
		rangeCurve="CannonCloseShotCurve";
	};
	class Shell155mm_midExp_SoundShader
	{
		samples[]+=
		{
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_midExp_05",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_midExp_06",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_midExp_07",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_midExp_08",
				1
			}
		};
	};
	class Shell155mm_tailForest_SoundShader
	{
		samples[]+=
		{
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailForest_05",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailForest_06",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailForest_07",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailForest_08",
				1
			}
		};
	};
	class Shell155mm_tailMeadows_SoundShader
	{
		samples[]+=
		{
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailMeadows_05",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailMeadows_06",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailMeadows_07",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailMeadows_08",
				1
			}
		};
	};
	class Shell155mm_tailHouses_SoundShader
	{
		samples[]+=
		{
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailHouses_05",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailHouses_06",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailHouses_07",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyA_tailHouses_08",
				1
			}
		};
	};
	class BombsHeavy_distExp_SoundShader
	{
		samples[]+=
		{
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyB_distExp_01",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyB_distExp_02",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellHeavyB_distExp_03",
				1
			}
		};
	};
	class Wind_Trees_Creaks_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Trees_Creaks_Distant_01",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Trees_Creaks_Distant_02",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Trees_Creaks_Distant_03",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Trees_Creaks_Distant_04",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Trees_Creaks_Distant_05",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Trees_Creaks_Distant_06",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Trees_Creaks_Distant_07",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Trees_Creaks_Distant_08",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Environment\SpotFx\Wind\Wind_Trees_Creaks_Distant_09",
				1
			}
		};
		volume="1.2 * 1.52 * (wind factor [0.4,0.7])";
		range=20;
		rangeCurve[]=
		{
			{0,0},
			{5,0.1},
			{10,0.25},
			{15,0.5},
			{20,1}
		};
		limitation=1;
	};
	class Wind_Trees_Creaks_Close_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_enoch\assets\environment\spotfx\wind\wind_trees_creaks_close_01",
				1
			},
			{
				"a3\sounds_f_enoch\assets\environment\spotfx\wind\wind_trees_creaks_close_02",
				1
			},
			{
				"a3\sounds_f_enoch\assets\environment\spotfx\wind\wind_trees_creaks_close_03",
				1
			},
			{
				"a3\sounds_f_enoch\assets\environment\spotfx\wind\wind_trees_creaks_close_04",
				1
			},
			{
				"a3\sounds_f_enoch\assets\environment\spotfx\wind\wind_trees_creaks_close_05",
				1
			},
			{
				"a3\sounds_f_enoch\assets\environment\spotfx\wind\wind_trees_creaks_close_06",
				1
			},
			{
				"a3\sounds_f_enoch\assets\environment\spotfx\wind\wind_trees_creaks_close_07",
				1
			},
			{
				"a3\sounds_f_enoch\assets\environment\spotfx\wind\wind_trees_creaks_close_08",
				1
			},
			{
				"a3\sounds_f_enoch\assets\environment\spotfx\wind\wind_trees_creaks_close_09",
				1
			}
		};
		volume="1.2 *1 * (wind factor [0.4,0.7])";
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{5,1},
			{10,0.5},
			{15,0.1},
			{20,0}
		};
		limitation=1;
	};
	class Wind_Tree_Creacking_SoundShader
	{
		limitation=1;
	};
	class DeminingDisruptor_01_Shot_mechanism_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_enoch\assets\arsenal\ugv_02\ugv_02_shotgun_mechanism_01",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\ugv_02\ugv_02_shotgun_mechanism_02",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\ugv_02\ugv_02_shotgun_mechanism_03",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\ugv_02\ugv_02_shotgun_mechanism_04",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\ugv_02\ugv_02_shotgun_mechanism_05",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\ugv_02\ugv_02_shotgun_mechanism_06",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\ugv_02\ugv_02_shotgun_mechanism_07",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\ugv_02\ugv_02_shotgun_mechanism_08",
				1
			}
		};
		volume=0.44999999;
		range=4;
	};
	class Van_02_PoliceSiren_01_Ext_SoundShader
	{
		volume="camPos * 1  * 0.7 * CustomSoundController1";
	};
	class Van_02_PoliceSiren_01_Int_SoundShader
	{
		volume="(1-camPos) * 1  * 1 * CustomSoundController1";
	};
	class Van_02_AmbulanceSiren_01_Ext_SoundShader
	{
		volume="camPos * 1  * 0.7 * CustomSoundController1";
	};
	class Van_02_AmbulanceSiren_01_Int_SoundShader
	{
		volume="(1-camPos) * 1  * 1 * CustomSoundController1";
	};
	class UXO_Exp_Low_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_Low_01",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_Low_02",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_Low_03",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_Low_04",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_Low_05",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_Low_06",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_Low_07",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_Low_08",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_Low_09",
				1
			}
		};
	};
	class UXO_Dist_Exp_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_01",
				1
			},
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_03",
				1
			},
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_04",
				1
			},
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_05",
				1
			},
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_06",
				1
			},
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_07",
				1
			}
		};
	};
	class ClusterBomb_Exp_Dist_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_01",
				1
			},
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_03",
				1
			},
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_04",
				1
			},
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_05",
				1
			},
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_06",
				1
			},
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_07",
				1
			},
			{
				"a3\sounds_f_orange\arsenal\explosives\clusterbomb\cluster_exp_dist_08",
				1
			}
		};
	};
	class Misc_Building_Sfx_Globe_SoundShader: Misc_Building_Sfx_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx001",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx002",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx003",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx004",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx005",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx006",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx007",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx008",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx009",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx010",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx011",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx012",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx013",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx014",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx015",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx016",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx019",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx020",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx021",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx022",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx023",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx024",
				1
			},
			{
				"A3\Sounds_F_Oldman\environment\sfx\misc\building\sfx025",
				1
			}
		};
	};
	class Mx_Mechanism_Enoch_SoundShader
	{
		samples[]+=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Arsenal\Mx\Mx_Mechanism_01",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Arsenal\Mx\Mx_Mechanism_02",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Arsenal\Mx\Mx_Mechanism_03",
				1
			}
		};
	};
	class Mx_Silencer_Mechanism_Enoch_SoundShader
	{
		samples[]+=
		{
			{
				"A3\Sounds_F_Enoch\Assets\Arsenal\Mx\Mx_Mechanism_01",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Arsenal\Mx\Mx_Mechanism_02",
				1
			},
			{
				"A3\Sounds_F_Enoch\Assets\Arsenal\Mx\Mx_Mechanism_03",
				1
			}
		};
	};
	class UAV_05_WindNoiseExt_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_jets\vehicles\air\uav_05\b_uav_05_engine_wind_ext",
				1
			}
		};
	};
	class Wind_LeavesA_SoundShader
	{
		volume="(rain factor [0.5,0.3]) * (wind factor [-0.1,0.8])";
	};
	class Wind_LeavesA_Narrow_SoundShader
	{
		volume="(rain factor [0.5,0.3]) * (wind factor [-0.1,0.8])";
	};
	class Wind_LeavesB_SoundShader
	{
		volume="(rain factor [0.5,0.3]) * (wind factor [-0.1,0.8])";
	};
	class Wind_LeavesC_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Exp\environment\elements\winds\wind_leavesC_1",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\elements\winds\wind_leavesC_2",
				1
			},
			{
				"A3\Sounds_F_Exp\environment\elements\winds\wind_leavesC_3",
				1
			}
		};
		volume="(rain factor [0.5,0.3]) * (wind factor [-0.1,0.8])";
	};
	class UXO_Debris_Dirt_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_01",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_02",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_03",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_04",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_05",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_06",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_07",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_08",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_09",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_10",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_11",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_12",
				1
			}
		};
	};
	class ClusterBomb_Debris_Dirt_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_01",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_02",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_03",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_04",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_05",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_06",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_07",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_08",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_09",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_10",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_11",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_12",
				1
			}
		};
	};
	class ClusterBomb_Debris_Hard_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_01",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_02",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_03",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_04",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_05",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_06",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_07",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_08",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_09",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_10",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_11",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\Debris_Short_12",
				1
			}
		};
	};
	class BulletSonicCrack_Gatling_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_gatling_01",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_gatling_02",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_gatling_03",
				1
			}
		};
	};
	class Tracks_Movement_Dirt_Ext_01_dirt_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\shared\Tracks_Surface_Movement\debris_dirt_metal_light_ext",
				1
			}
		};
		frequency=1;
		volume="2 * (((0.35 * (		(mud+gravel+grass) * (latSlipDrive factor[-0.01, -0.15]) + (mud+gravel+grass) * (latSlipDrive factor[0.01, 0.15]))) * (speed factor [0,10])) + (0.35 * ((mud+gravel+grass) * (speed factor[-0, -5]) * (latSlipDrive factor[-0.01, -0.06]) + (mud+gravel+grass) * (speed factor[-0, -5]) * (latSlipDrive factor[0.01, 0.06]))) + ((0.3*(asphalt * (latSlipDrive factor [0.01, 015]) + 	asphalt * (latSlipDrive factor [-0.01, -0.15]))) * (speed factor[5,10])) + ((0.55*(asphalt * (latSlipDrive factor [0.01, 015]) + 	asphalt * (latSlipDrive factor [-0.01, -0.15]))) * (speed factor[0,-7])) + ((mud+gravel+grass)*0.1*(speed factor[0, -10])))";
		range=60;
	};
	class Tracks_Movement_Dirt_Ext_01_dirt_back_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\shared\Tracks_Surface_Movement\debris_dirt_metal_light_ext_back",
				1
			}
		};
		frequency=1;
		volume="2 * (((0.35 * (		(mud+gravel+grass) * (latSlipDrive factor[-0.01, -0.15]) + (mud+gravel+grass) * (latSlipDrive factor[0.01, 0.15]))) * (speed factor [0,10])) + (0.35 * ((mud+gravel+grass) * (speed factor[-0, -5]) * (latSlipDrive factor[-0.01, -0.06]) + (mud+gravel+grass) * (speed factor[-0, -5]) * (latSlipDrive factor[0.01, 0.06]))) + ((0.3*(asphalt * (latSlipDrive factor [0.01, 015]) + 	asphalt * (latSlipDrive factor [-0.01, -0.15]))) * (speed factor[5,10])) + ((0.55*(asphalt * (latSlipDrive factor [0.01, 015]) + 	asphalt * (latSlipDrive factor [-0.01, -0.15]))) * (speed factor[0,-7])) + ((mud+gravel+grass)*0.1*(speed factor[0, -10])))";
		range=60;
	};
	class Tracks_Surface_Hard_Int_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\shared\Tracks_Surface_Movement\tracks_surface_movement_asphalt_int",
				1
			}
		};
	};
	class Tracks_Surface_Soft_Ext_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\shared\Tracks_Surface_Movement\tracks_surface_movement_grass",
				1
			}
		};
	};
	class VLS_01_distShot_SoundShader
	{
		samples[]+=
		{
			{
				"A3\Sounds_F\arsenal\weapons_vehicles\Missiles\VLS_01_Launch_Distant_04",
				1
			}
		};
	};
	class ClusterBomb_Exp_Close_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_01",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_02",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_03",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_04",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_05",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_06",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_07",
				1
			},
			{
				"A3\Sounds_F_Orange\arsenal\explosives\clusterbomb\ClusterBomb_Exp_08",
				1
			}
		};
	};
	class Railgun_01_Tail_SoundShader
	{
		samples[]=
		{
			{
				"a3\Sounds_F_Decade\Assets\Arsenal\Railgun_01\Railgun_01_Tail_Open_01",
				1
			},
			{
				"a3\Sounds_F_Decade\Assets\Arsenal\Railgun_01\Railgun_01_Tail_Open_02",
				1
			},
			{
				"a3\Sounds_F_Decade\Assets\Arsenal\Railgun_01\Railgun_01_Tail_Open_03",
				1
			},
			{
				"a3\Sounds_F_Decade\Assets\Arsenal\Railgun_01\Railgun_01_Tail_Open_04",
				1
			},
			{
				"a3\Sounds_F_Decade\Assets\Arsenal\Railgun_01\Railgun_01_Tail_Open_05",
				1
			}
		};
		volume=2.5;
		range=2200;
		limitation=0;
		rangeCurve[]=
		{
			{0,1},
			{1000,0.5},
			{2200,0}
		};
	};
	class Shell19mm25mm_closeExp_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellLightC_closeExp_01",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellLightC_closeExp_02",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellLightC_closeExp_03",
				1
			}
		};
		volume=1;
		range=1000;
		rangeCurve[]=
		{
			{0,1},
			{300,1},
			{1000,0}
		};
	};
	class Shell19mm25mm_midExp_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellLightC_midExp_01",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellLightC_midExp_02",
				1
			},
			{
				"A3\Sounds_F\arsenal\explosives\shells\ShellLightC_midExp_03",
				1
			}
		};
		volume=1.3;
		range=1000;
		rangeCurve[]=
		{
			{0,0},
			{500,1},
			{1000,1}
		};
	};
	class Engine_Base_RPM0_EXT_SoundShader;
	class Engine_Base_RPM1_EXT_SoundShader;
	class Engine_Base_RPM2_EXT_SoundShader;
	class Engine_Base_RPM3_EXT_SoundShader;
	class Engine_Base_RPM0_INT_SoundShader;
	class Engine_Base_RPM1_INT_SoundShader;
	class Engine_Base_RPM2_INT_SoundShader;
	class Engine_Base_RPM3_INT_SoundShader;
	class MBT_02_Engine_EXT_Burst_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_EXT_Burst01",
				1
			},
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_EXT_Burst02",
				1
			}
		};
		volume="engineOn * 1.2 * 0.7 * (rpm factor[0,10])";
		frequency=1.05;
		range="1*150";
	};
	class MBT_02_Engine_INT_Burst_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_INT_Burst01",
				1
			},
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_INT_Burst02",
				1
			}
		};
		volume="engineOn * 1.2 * 1.5 * (rpm factor[0,10])";
		frequency=1.05;
	};
	class MBT_02_Turbine01_Int_Tonal_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Turbine01_Int_Tonal",
				1
			},
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Turbine01_Int_Tonal0",
				1
			},
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Turbine01_Int_Tonal1",
				1
			}
		};
		frequency="1.1 + 0.05*(rpm factor [1000,2700]) + 0.1*thrust";
		volume="engineOn * (rpm factor[100,1000])*(2 + 0.2*thrust)*0.5";
	};
	class MBT_02_Engine_RPM0_EXT_SoundShader: Engine_Base_RPM0_EXT_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_EXT_RPM0",
				1
			}
		};
		frequency="1 + 0.1 * (1 + 0.5  * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) - 0))";
		volume="engineOn * 0.75 * 1 * (rpm factor [0 *1000, (0 *1000 + 0.2 *(1000-0 *1000))]) * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor [(2000 - 1000)/(4000 - 1000) - (((2000 - 1000)/(4000 - 1000) - 0) - (1.5 * ((2000 - 1000)/(4000 - 1000) - 0)))/2, 0])";
		range="6*225";
	};
	class MBT_02_Engine_RPM1_EXT_SoundShader: Engine_Base_RPM1_EXT_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_EXT_RPM1",
				1
			}
		};
		frequency="1 + 0.1 * (1 + 0.5  * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) - (2000 - 1000)/(4000 - 1000)))";
		volume="engineOn * 0.75 * 1 * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor[0, (2000 - 1000)/(4000 - 1000) - (((2000 - 1000)/(4000 - 1000) - 0) - (1.5 * ((2000 - 1000)/(4000 - 1000) - 0)))/2]) * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor [(3000 - 1000)/(4000 - 1000) - (((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000)) - (1.5 * ((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000))))/2, (2000 - 1000)/(4000 - 1000) + (((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000)) - (1.5 * ((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000))))/2])";
		range="6*230";
	};
	class MBT_02_Engine_RPM2_EXT_SoundShader: Engine_Base_RPM2_EXT_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_EXT_RPM2",
				1
			}
		};
		frequency="1 + 0.1 * (1 + 0.5  * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) - (3000 - 1000)/(4000 - 1000)))";
		volume="engineOn * 0.75 * 1 * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor[(2000 - 1000)/(4000 - 1000) + (((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000)) - (1.5 * ((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000))))/2, (3000 - 1000)/(4000 - 1000) - (((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000)) - (1.5 * ((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000))))/2]) * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor [(4000 - 1000)/(4000 - 1000) - (((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000)) - (1.5 * ((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000))))/2, (3000 - 1000)/(4000 - 1000) + (((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000)) - (1.5 * ((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000))))/2])";
		range="6*235";
	};
	class MBT_02_Engine_RPM3_EXT_SoundShader: Engine_Base_RPM3_EXT_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_EXT_RPM3",
				1
			}
		};
		frequency="1 + 0.1 * (1 + 0.5  * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) - (4000 - 1000)/(4000 - 1000)))";
		volume="engineOn * 0.75 * 1 * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor[(3000 - 1000)/(4000 - 1000) + (((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000)) - (1.5 * ((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000))))/2, (4000 - 1000)/(4000 - 1000) - (((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000)) - (1.5 * ((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000))))/2])";
		range="6*240";
	};
	class MBT_02_Engine_RPM0_INT_SoundShader: Engine_Base_RPM0_INT_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_INT_RPM0",
				1
			}
		};
		frequency="1 + 0.1 * (1 + 0.5  * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) - 0))";
		volume="engineOn * 1 * 1.5 * (rpm factor [0 *1000, (0 *1000 + 0.2 *(1000-0 *1000))]) * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor [(2000 - 1000)/(4000 - 1000) - (((2000 - 1000)/(4000 - 1000) - 0) - (1.5 * ((2000 - 1000)/(4000 - 1000) - 0)))/2, 0])";
		range="6*225";
	};
	class MBT_02_Engine_RPM1_INT_SoundShader: Engine_Base_RPM1_INT_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_INT_RPM1",
				1
			}
		};
		frequency="1 + 0.1 * (1 + 0.5  * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) - (2000 - 1000)/(4000 - 1000)))";
		volume="engineOn * 1 * 1.5 * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor[0, (2000 - 1000)/(4000 - 1000) - (((2000 - 1000)/(4000 - 1000) - 0) - (1.5 * ((2000 - 1000)/(4000 - 1000) - 0)))/2]) * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor [(3000 - 1000)/(4000 - 1000) - (((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000)) - (1.5 * ((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000))))/2, (2000 - 1000)/(4000 - 1000) + (((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000)) - (1.5 * ((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000))))/2])";
		range="6*230";
	};
	class MBT_02_Engine_RPM2_INT_SoundShader: Engine_Base_RPM2_INT_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_INT_RPM2",
				1
			}
		};
		frequency="1 + 0.1 * (1 + 0.5  * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) - (3000 - 1000)/(4000 - 1000)))";
		volume="engineOn * 1 * 1.5 * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor[(2000 - 1000)/(4000 - 1000) + (((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000)) - (1.5 * ((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000))))/2, (3000 - 1000)/(4000 - 1000) - (((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000)) - (1.5 * ((3000 - 1000)/(4000 - 1000) - (2000 - 1000)/(4000 - 1000))))/2]) * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor [(4000 - 1000)/(4000 - 1000) - (((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000)) - (1.5 * ((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000))))/2, (3000 - 1000)/(4000 - 1000) + (((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000)) - (1.5 * ((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000))))/2])";
		range="6*235";
	};
	class MBT_02_Engine_RPM3_INT_SoundShader: Engine_Base_RPM3_INT_SoundShader
	{
		samples[]=
		{
			{
				"A3\Sounds_F\vehicles2\armor\MBT_02\MBT_02_Engine_INT_RPM3",
				1
			}
		};
		frequency="1 + 0.1 * (1 + 0.5  * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) - (4000 - 1000)/(4000 - 1000)))";
		volume="engineOn * 1 * 1.5 * ((1 + 0.1*thrust)*0.6) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4]) - 0.3 * (1 - 0.8 *thrust)*((1-0.5  ) * (speed factor [0, 21.2304]) + 0.5   * (rpm factor [1000,	2700])) - 0.2*((abs(speed)) factor [2, 6]) + 0.2*((abs(speed)) factor [0, 4])*((abs(speed)) factor [0, 4])) + 0.5*(speed factor[0.3,0]) * ((angVelocity factor[0,0.8]) - (rpm factor [1000,	2700])) factor[(3000 - 1000)/(4000 - 1000) + (((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000)) - (1.5 * ((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000))))/2, (4000 - 1000)/(4000 - 1000) - (((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000)) - (1.5 * ((4000 - 1000)/(4000 - 1000) - (3000 - 1000)/(4000 - 1000))))/2])";
		range="6*240";
	};
	class BulletSonicCrack_tailMeadow_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailmeadow01",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailmeadow02",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailmeadow03",
				1
			}
		};
	};
	class BulletSonicCrack_tailForest_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailforest01",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailforest02",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailforest03",
				1
			}
		};
	};
	class BulletSonicCrack_tailTrees_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailtrees01",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailtrees02",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailtrees03",
				1
			}
		};
	};
	class BulletSonicCrack_tailHouses_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailhouses01",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailhouses02",
				1
			},
			{
				"a3\sounds_f_enoch\assets\arsenal\bullet_sonic_crack\soniccrack_tailhouses03",
				1
			}
		};
	};
	class Mx_silencerTailForest_Enoch_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Mx_silencerTailHouses_Enoch_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Mx_silencerTailMeadows_Enoch_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class Mx_silencerTailTrees_Enoch_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class 4Five_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class 4Five_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class 4Five_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class 4Five_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class ACPC2_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class ACPC2_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class ACPC2_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class ACPC2_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class P07_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class P07_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class P07_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class P07_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Rook40_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Rook40_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Rook40_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class Rook40_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR01_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR01_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR01_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class DMR01_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Mk18_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Mk18_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Mk18_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class Mk18_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Mk200_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Mk200_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Mk200_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class Mk200_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Katiba_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Katiba_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Katiba_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class Katiba_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Mk20_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Mk20_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Mk20_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class Mk20_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class TRG20_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class TRG20_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class TRG20_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class TRG20_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SMGPDW2000_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SMGPDW2000_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SMGPDW2000_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class SMGPDW2000_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SMGSting_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SMGSting_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SMGSting_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class SMGSting_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SMGVermin_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SMGVermin_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SMGVermin_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class SMGVermin_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR02_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR02_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR02_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class DMR02_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR03_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR03_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR03_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class DMR03_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR04_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR04_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR04_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class DMR04_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR05_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR05_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR05_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class DMR05_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR06_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR06_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR06_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class DMR06_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class MMG01_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class MMG01_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class MMG01_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class MMG01_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class MMG02_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class MMG02_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class MMG02_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class MMG02_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class ADR_97_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class ADR_97_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class ADR_97_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class ADR_97_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SyndikatLMG_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SyndikatLMG_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SyndikatLMG_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class SyndikatLMG_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR07_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR07_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR07_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class DMR07_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Rogue9_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Rogue9_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Rogue9_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class Rogue9_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class AK12_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class AK12_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class AK12_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class AK12_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Type115_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Type115_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Type115_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class Type115_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class CAR_95_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class CAR_95_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class CAR_95_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class CAR_95_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SPAR01_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SPAR01_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SPAR01_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class SPAR01_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SPAR02_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SPAR02_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SPAR02_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class SPAR02_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SPAR_17_silencerTailForest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SPAR_17_silencerTailHouses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class SPAR_17_silencerTailMeadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class SPAR_17_silencerTailTrees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Msbs65_01_Tail_Silencer_Forest_SoundShader
	{
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Msbs65_01_Tail_Silencer_Houses_SoundShader
	{
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class Msbs65_01_Tail_Silencer_Meadows_SoundShader
	{
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class Msbs65_01_Tail_Silencer_Trees_SoundShader
	{
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR04_tailForest_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_mark\arsenal\weapons\longrangerifles\dmr_04_asp1_kir\dmr_04_tail_forest",
				1
			}
		};
		volume="(forest/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR04_tailHouses_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_mark\arsenal\weapons\longrangerifles\dmr_04_asp1_kir\dmr_04_tail_houses",
				1
			}
		};
		volume="(houses/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
	class DMR04_tailInterior_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_mark\arsenal\weapons\longrangerifles\dmr_04_asp1_kir\dmr_04_tail_interior",
				1
			}
		};
	};
	class DMR04_tailMeadows_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_mark\arsenal\weapons\longrangerifles\dmr_04_asp1_kir\dmr_04_tail_meadows",
				1
			}
		};
		volume="(meadows + sea)/(forest + houses + meadows + sea + trees) * (1-interior)";
	};
	class DMR04_tailTrees_SoundShader
	{
		samples[]=
		{
			{
				"a3\sounds_f_mark\arsenal\weapons\longrangerifles\dmr_04_asp1_kir\dmr_04_tail_trees",
				1
			}
		};
		volume="(trees/(forest + houses + meadows + sea + trees)) * (1-interior)";
	};
};
class CfgWorlds
{
	class CAWorld;
	class Enoch: CAWorld
	{
		class AmbientA3
		{
			class Radius440_500
			{
				areaSpawnRadius=70;
				areaMaxRadius=200;
			};
		};
	};
	class Tanoa: CAWorld
	{
		class AmbientA3
		{
			class Radius440_500
			{
				areaSpawnRadius=70;
				areaMaxRadius=200;
			};
		};
	};
};
delete RainRoofSmall3DProcessingType;
delete RainRoofMedium3DProcessingType;
delete RainRoofLarge3DProcessingType;
delete PLant3DProcessingType;
delete SpotFx3DProcessingType;
delete ShowerNozzle3DProcessingType;
delete ShowerCenter3DProcessingType;
class CfgSound3DProcessors
{
	class Insect3DProcessingType
	{
		type="panner";
		innerRange=0;
		range=0;
		rangeCurve="objectTransitionCurve";
	};
	class Bird3DProcessingType;
	class Birds3DProcessingType: Bird3DProcessingType
	{
	};
	class WindTreesCreaks_3DProcessingType
	{
		type="panner";
		innerRange=1;
		range=4;
		rangeCurve="objectTransitionCurve";
	};
	class ForestDay_3DProcessingType
	{
		type="surround_panner";
		radius=10;
		volumeAll=1;
		reference="camera";
	};
	class ForestWind_3DProcessingType
	{
		type="surround_panner";
		radius=10;
		volumeAll=1;
		reference="camera";
	};
	class MeadowWind_3DProcessingType
	{
		type="surround_panner";
		radius=10;
		volumeAll=1;
		reference="camera";
	};
	class SpotFx3DProcessingType
	{
		type="emitter";
		innerRange=0;
		range=1;
		radius=2;
		rangeCurve="Smooth1Curve";
	};
	class ShowerNozzle3DProcessingType
	{
		type="emitter";
		innerRange=0;
		range=0.1;
		radius=2;
		rangeCurve="objectTransitionCurve";
	};
	class ShowerCenter3DProcessingType
	{
		type="emitter";
		innerRange=1;
		range=15;
		radius=2;
		rangeCurve="objectTransitionCurve";
	};
	class Flies3DProcessingType
	{
		type="panner";
		innerRange=1.5;
		range=3;
		rangeCurve="objectTransitionCurve";
	};
	class Tree3DProcessingType
	{
		type="emitter";
		innerRange=0;
		range=5;
		radius=1;
		rangeCurve="Smooth1Curve";
	};
	class SmallPineTree3DProcessingType
	{
		type="emitter";
		innerRange=0;
		range=2;
		radius=0.25;
		rangeCurve="Smooth1Curve";
	};
	class animal3DProcessingType
	{
		type="panner";
		innerRange=2;
		range=4;
	};
	class WindPlantSmall3DProcessingType
	{
		type="panner";
		innerRange=0;
		range=0;
		rangeCurve="objectTransitionCurve";
	};
	class WindPlantMedium3DProcessingType
	{
		type="panner";
		innerRange=3;
		range=5;
		rangeCurve="objectTransitionCurve";
	};
	class WindPlantLarge3DProcessingType
	{
		type="panner";
		innerRange=3;
		range=10;
		rangeCurve="objectTransitionCurve";
	};
};
class CfgSurfaces
{
	class Default
	{
		files="default";
		rough=0.075000003;
		dust=0.1;
		lucidity=1;
		isWater=0;
		friction=1;
		soundEnviron="normalExt";
		character="Empty";
		impact="default_Mat";
		grassCover=0;
		tracksAlpha=1;
		transparency=-1;
		AIAvoidStance=0;
		surfaceFriction=2;
		restitution=0.25;
		maxSpeedCoef=1;
	};
	class Water
	{
		files="more_anim*";
		rough=0;
		dust=0;
		lucidity=1;
		maxSpeedCoef=1;
		soundEnviron="water";
		friction=1;
		restitution=0;
		isWater=1;
		character="Empty";
		impact="hitWater";
		grassCover=0;
		soundHit="water";
	};
	class SurfRoadDirt: Default
	{
		access=2;
		files="surf_roaddirt_*";
		character="Empty";
		soundEnviron="gravel";
		soundHit="hard_ground";
		rough=0.050000001;
		dust=0.40000001;
		lucidity=1;
		maxSpeedCoef=1;
		impact="hitGroundHard";
		surfaceFriction=1.4;
		restitution=0.19;
	};
	class SurfRoadConcrete: Default
	{
		access=2;
		files="surf_roadconcrete_*";
		character="Empty";
		soundEnviron="concrete";
		soundHit="hard_ground";
		rough=0.050000001;
		dust=0.15000001;
		lucidity=0.30000001;
		impact="hitGroundHard";
		surfaceFriction=1.8;
	};
	class SurfRoadTarmac: Default
	{
		access=2;
		files="surf_roadtarmac_*";
		character="Empty";
		soundEnviron="tarmac";
		soundHit="hard_ground";
		rough=0.050000001;
		dust=0.02;
		lucidity=0.5;
		impact="hitGroundHard";
		surfaceFriction=2;
		restitution=0.2;
	};
	class SurfWood: Default
	{
		access=2;
		files="surf_wood_*";
		character="Empty";
		soundEnviron="wood";
		rough=0.050000001;
		dust=0.0099999998;
		lucidity=0.69999999;
		surfaceFriction=1.5;
		restitution=0.2;
		maxSpeedCoef=1;
		soundHit="wood";
	};
	class SurfMetal: Default
	{
		access=2;
		files="surf_metal_*";
		character="Empty";
		soundEnviron="metal";
		rough=0.050000001;
		dust=0;
		lucidity=0.69999999;
		AIAvoidStance=1;
		surfaceFriction=1.7;
		restitution=0.25;
		maxSpeedCoef=0.94999999;
		soundHit="metal";
	};
	class SurfRoofTin: Default
	{
		access=2;
		files="surf_rooftin_*";
		character="Empty";
		soundEnviron="wavymetal";
		rough=0.050000001;
		dust=0.029999999;
		lucidity=0.69999999;
		surfaceFriction=1.2;
		restitution=0.125;
		maxSpeedCoef=0.86000001;
		soundHit="metal";
	};
	class SurfRoofTiles: Default
	{
		access=2;
		files="surf_rooftiles_*";
		character="Empty";
		soundEnviron="roof_tiles";
		rough=0.050000001;
		dust=0.050000001;
		lucidity=0.69999999;
		surfaceFriction=1.2;
		restitution=0.125;
		maxSpeedCoef=0.86000001;
	};
	class SurfIntWood: Default
	{
		access=2;
		files="surfint_wood_*";
		character="Empty";
		soundEnviron="int_wood";
		rough=0.050000001;
		dust=0.0099999998;
		lucidity=0.69999999;
		AIAvoidStance=1;
		surfaceFriction=1.5;
		restitution=0.2;
		maxSpeedCoef=1;
		soundHit="wood";
	};
	class SurfIntConcrete: Default
	{
		access=2;
		files="surfint_concrete_*";
		character="Empty";
		soundEnviron="int_concrete";
		rough=0.050000001;
		dust=0.029999999;
		lucidity=0.69999999;
		AIAvoidStance=1;
	};
	class SurfIntTiles: Default
	{
		access=2;
		files="surfint_tiles_*";
		character="Empty";
		soundEnviron="int_tiles";
		rough=0.050000001;
		dust=0;
		lucidity=0.69999999;
		AIAvoidStance=1;
		surfaceFriction=1.2;
		restitution=0.125;
		maxSpeedCoef=0.86000001;
	};
	class SurfIntMetal: Default
	{
		access=2;
		files="surfint_metal_*";
		character="Empty";
		soundEnviron="int_metal";
		rough=0.050000001;
		dust=0;
		lucidity=0.69999999;
		AIAvoidStance=1;
		surfaceFriction=1.7;
		restitution=0.25;
		maxSpeedCoef=0.94999999;
		soundHit="metal";
	};
	class SurfWater: Default
	{
		access=2;
		files="surf_water_*";
		character="Empty";
		soundEnviron="water";
		friction=0.0099999998;
		restitution=0;
		isWater=1;
		rough=0.050000001;
		dust=0;
		lucidity=1;
		soundHit="water";
	};
	class TEST_SurfNormal: Default
	{
		access=2;
		files="test_surf_normal_*";
		character="Empty";
		soundEnviron="normal";
		rough=0.050000001;
		dust=0.1;
		lucidity=1;
	};
	class GdtStratisConcrete: Default
	{
		access=2;
		files="gdt_strconcrete_*";
		character="Empty";
		soundEnviron="concrete";
		soundHit="concrete";
		rough=0.050000001;
		maxSpeedCoef=1;
		dust=0.15000001;
		lucidity=0.30000001;
		grassCover=0;
		impact="hitConcrete";
		maxClutterColoringCoef=1.35;
		surfaceFriction=1.8;
	};
	class GdtStratisBeach: Default
	{
		access=2;
		files="gdt_strbeach_*";
		character="Empty";
		soundEnviron="sand";
		soundHit="soft_ground";
		rough=0.1;
		dust=0.5;
		lucidity=1.25;
		grassCover=0;
		impact="hitGroundSoft";
		surfaceFriction=1;
		restitution=0.050000001;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtStratisDirt: Default
	{
		access=2;
		files="gdt_strdirt_*";
		character="Empty";
		soundEnviron="dirt";
		soundHit="soft_ground";
		rough=0.090000004;
		dust=0.5;
		lucidity=1;
		grassCover=0.029999999;
		impact="hitGroundSoft";
		surfaceFriction=1.4;
		restitution=0.19;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtStratisSeabedCluttered: Default
	{
		access=2;
		files="gdt_strseabed_*";
		character="SeabedClutter";
		soundEnviron="gravel";
		soundHit="hard_ground";
		rough=0.15000001;
		dust=0.75;
		lucidity=200;
		grassCover=0.050000001;
		surfaceFriction=1;
		restitution=0.050000001;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtStratisSeabed: Default
	{
		access=2;
		files="gdt_strdeepsea_*";
		character="Empty";
		soundEnviron="gravel";
		soundHit="hard_ground";
		rough=0.15000001;
		dust=0.75;
		lucidity=150;
		grassCover=0;
		surfaceFriction=1;
		restitution=0.050000001;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtStratisDryGrass: Default
	{
		access=2;
		files="gdt_strdrygrass_*";
		character="StratisDryGrassClutter";
		soundEnviron="drygrass";
		soundHit="foliage";
		rough=0.079999998;
		dust=0.75;
		lucidity=2;
		grassCover=0.1;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtStratisGreenGrass: Default
	{
		access=2;
		files="gdt_strgreengrass_*";
		character="StratisGreenGrassClutter";
		soundEnviron="grass";
		soundHit="foliage";
		rough=0.079999998;
		dust=0.15000001;
		lucidity=4;
		grassCover=0.050000001;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtStratisRocky: Default
	{
		access=2;
		files="gdt_strrocky_*";
		character="StratisRockyClutter";
		soundEnviron="gravel";
		soundHit="hard_ground";
		rough=0.12;
		dust=0.40000001;
		lucidity=1.5;
		grassCover=0.02;
		impact="hitGroundHard";
		surfaceFriction=1.8;
		restitution=0.25;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtStratisThistles: Default
	{
		access=2;
		files="gdt_strthistles_*";
		character="StratisThistlesClutter";
		soundEnviron="stony";
		soundHit="foliage";
		rough=0.12;
		dust=0.60000002;
		lucidity=3.5;
		grassCover=0;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtStratisForestPine: Default
	{
		access=2;
		files="gdt_strforest_pine_*";
		character="StratisForestPineClutter";
		soundEnviron="drygrass";
		soundHit="foliage";
		rough=0.12;
		dust=0.40000001;
		lucidity=3.5;
		grassCover=0.039999999;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtRubble: Default
	{
		access=2;
		files="gdt_rubble_*";
		character="RubbleClutter";
		soundEnviron="debris";
		soundHit="building";
		rough=0.2;
		dust=0.5;
		lucidity=3;
		grassCover=0;
		impact="hitGroundHard";
		surfaceFriction=1.2;
		restitution=0.125;
		maxSpeedCoef=0.86000001;
		maxClutterColoringCoef=1.35;
	};
	class GdtForestPine: Default
	{
		access=2;
		files="gdt_forest_pine_*";
		character="ForestPineClutter";
		soundEnviron="drygrass";
		soundHit="foliage";
		rough=0.12;
		dust=0.40000001;
		lucidity=3.5;
		grassCover=0.039999999;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtConcrete: Default
	{
		access=2;
		files="gdt_concrete_*";
		character="Empty";
		soundEnviron="concrete";
		soundHit="concrete";
		rough=0.050000001;
		dust=0.050000001;
		lucidity=0.30000001;
		grassCover=0;
		impact="hitConcrete";
		maxClutterColoringCoef=1.35;
		surfaceFriction=1.8;
		restitution=0.25;
	};
	class GdtSoil: Default
	{
		access=2;
		files="gdt_soil_*";
		character="Empty";
		soundEnviron="dirt";
		soundHit="soft_ground";
		rough=0.090000004;
		dust=0.5;
		lucidity=1;
		grassCover=0;
		surfaceFriction=1.4;
		restitution=0.19;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtBeach: Default
	{
		access=2;
		files="gdt_beach_*";
		character="Empty";
		soundEnviron="sand_exp";
		soundHit="soft_ground";
		rough=0.1;
		dust=0.5;
		lucidity=1.25;
		grassCover=0;
		maxClutterColoringCoef=1.5;
		impact="hitGroundSoft";
		surfaceFriction=1;
		restitution=0.050000001;
		maxSpeedCoef=1;
	};
	class GdtRock: Default
	{
		access=2;
		files="gdt_rock_*";
		character="Empty";
		soundEnviron="rock";
		soundHit="hard_ground";
		rough=0.2;
		dust=0.5;
		lucidity=1;
		grassCover=0;
		impact="hitGroundHard";
		surfaceFriction=1.8;
		restitution=0.25;
		maxSpeedCoef=0.86000001;
		maxClutterColoringCoef=1.35;
	};
	class GdtDead: Default
	{
		access=2;
		files="gdt_dead_*";
		character="Empty";
		soundEnviron="sand";
		soundHit="soft_ground";
		rough=0.050000001;
		dust=0.40000001;
		lucidity=0.5;
		grassCover=0;
		impact="hitGroundSoft";
		surfaceFriction=1.4;
		restitution=0.19;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtDirt: Default
	{
		access=2;
		files="gdt_dirt_*";
		character="GrassDryClutter";
		soundEnviron="dirt";
		soundHit="hard_ground";
		rough=0.090000004;
		dust=0.5;
		lucidity=1;
		grassCover=0.029999999;
		impact="hitGroundSoft";
		surfaceFriction=1.4;
		restitution=0.19;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtDesert: Default
	{
		access=2;
		files="gdt_desert_*";
		character="Empty";
		soundEnviron="sand";
		soundHit="soft_ground";
		rough=0.11;
		dust=0.5;
		lucidity=2.5;
		grassCover=0;
		impact="hitGroundSoft";
		surfaceFriction=1;
		restitution=0.050000001;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtGrassGreen: Default
	{
		access=2;
		files="gdt_grass_green_*";
		character="GrassGreenClutter";
		soundEnviron="grass";
		soundHit="foliage";
		rough=0.079999998;
		dust=0.050000001;
		lucidity=4;
		grassCover=0.050000001;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtGrassDry: Default
	{
		access=2;
		files="gdt_dry_grass_*";
		character="GrassDryClutter";
		soundEnviron="drygrass";
		soundHit="foliage";
		rough=0.079999998;
		dust=0.5;
		lucidity=2;
		grassCover=0.1;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtGrassWild: Default
	{
		access=2;
		files="gdt_wild_grass_*";
		character="GrassWildClutter";
		soundEnviron="drygrass";
		soundHit="foliage";
		rough=0.1;
		dust=0.57999998;
		lucidity=2.5;
		grassCover=0.050000001;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtWeed: Default
	{
		access=2;
		files="gdt_weed_*";
		character="WeedClutter";
		soundEnviron="drygrass";
		soundHit="foliage";
		rough=0.12;
		dust=0.16;
		lucidity=2;
		grassCover=0.050000001;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtWildField: Default
	{
		access=2;
		files="gdt_wildfield_*";
		character="WildFieldClutter";
		soundEnviron="drygrass";
		soundHit="foliage";
		rough=0.1;
		dust=0.33000001;
		lucidity=1.5;
		grassCover=0.1;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtThorn: Default
	{
		access=2;
		files="gdt_thorn_*";
		character="ThornClutter";
		soundEnviron="stony";
		soundHit="hard_ground";
		rough=0.12;
		dust=0.43000001;
		lucidity=3.5;
		grassCover=0.15000001;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtStony: Default
	{
		access=2;
		files="gdt_stony_*";
		character="StonyClutter";
		soundEnviron="rock";
		soundHit="hard_ground";
		rough=0.12;
		dust=0.33000001;
		lucidity=1.5;
		grassCover=0;
		impact="hitGroundHard";
		surfaceFriction=1.3;
		restitution=0.175;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtStonyThistle: Default
	{
		access=2;
		files="gdt_thistle_stony_*";
		character="StonyThistleClutter";
		soundEnviron="stony";
		soundHit="hard_ground";
		rough=0.15000001;
		dust=0.41999999;
		lucidity=1.5;
		grassCover=0.029999999;
		impact="hitGroundHard";
		surfaceFriction=1.3;
		restitution=0.175;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtMud: Default
	{
		access=2;
		files="gdt_mud_*";
		character="MudClutter";
		soundEnviron="dirt";
		soundHit="soft_ground";
		rough=0.15000001;
		dust=0.31999999;
		lucidity=1.5;
		grassCover=0.039999999;
		impact="hitGroundHard";
		maxClutterColoringCoef=1.35;
		maxSpeedCoef=1;
		surfaceFriction=1;
		restitution=0.1;
	};
	class GdtMarsh: Default
	{
		access=2;
		files="gdt_marsh_*";
		character="Empty";
		soundEnviron="dirt";
		soundHit="soft_ground";
		rough=0.15000001;
		dust=0.1;
		lucidity=1.5;
		grassCover=0;
		surfaceFriction=1;
		restitution=0.1;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class GdtSeabed: Default
	{
		access=2;
		files="gdt_seabed_*";
		character="SeabedClutter";
		soundEnviron="gravel";
		soundHit="hard_ground";
		rough=0.15000001;
		dust=0.75;
		lucidity=200;
		grassCover=0;
		surfaceFriction=1;
		restitution=0.050000001;
		maxSpeedCoef=1;
		maxClutterColoringCoef=1.35;
	};
	class concrete: GdtStratisConcrete
	{
		files="beton";
		character="Empty";
		lucidity=0.30000001;
	};
	class concrete_out: GdtStratisConcrete
	{
		files="betonout";
		character="Empty";
		lucidity=0.30000001;
	};
	class concrete_inside: GdtStratisConcrete
	{
		files="betonin";
		character="Empty";
		lucidity=0.30000001;
		soundEnviron="int_concrete";
		AIAvoidStance=1;
	};
	class dirtrunway: GdtStratisDirt
	{
		files="dirtrunway*";
		rough=0.039999999;
		surfaceFriction=1.4;
		restitution=0.19;
		maxSpeedCoef=1;
	};
	class road: GdtConcrete
	{
		files="cesta*";
		character="Empty";
	};
	class floor: GdtStratisConcrete
	{
		files="dlazbaout";
		character="Empty";
	};
	class floor_inside: GdtStratisConcrete
	{
		files="dlazbain";
		character="Empty";
		soundEnviron="int_tiles";
		AIAvoidStance=1;
	};
	class carpet_inside: GdtConcrete
	{
		files="dum_mesto_koberec*";
		character="Empty";
		soundEnviron="int_concrete";
		AIAvoidStance=1;
	};
	class carpet: GdtConcrete
	{
		files="koberec*";
		character="Empty";
		soundEnviron="concrete";
	};
	class mud: GdtStratisDirt
	{
		files="hlina*";
		character="Empty";
	};
	class concrete_hall: concrete
	{
		files="chodba_beton*";
		character="Empty";
		soundEnviron="int_concrete";
		AIAvoidStance=1;
	};
	class stones: GdtStony
	{
		files="kameny*";
		character="Empty";
	};
	class cardboard: concrete
	{
		files="lepenka*";
	};
	class lino: concrete
	{
		files="lino*";
		soundEnviron="int_concrete";
		AIAvoidStance=1;
	};
	class steel: GdtStony
	{
		files="ocel*";
		character="Empty";
		soundEnviron="metal";
		AIAvoidStance=1;
		soundHit="metal";
	};
	class trash: GdtRubble
	{
		files="odpadky*";
		character="Empty";
	};
	class parquet: concrete
	{
		files="parkety*";
		soundEnviron="int_wood";
		AIAvoidStance=1;
		soundHit="wood";
	};
	class sand: GdtStratisBeach
	{
		files="pisek*";
		character="Empty";
	};
	class metalPlate: steel
	{
		files="plech*";
		character="Empty";
		soundHit="metal_plate";
	};
	class woodenFloor: concrete
	{
		files="podlaha_prkna*";
		character="Empty";
		soundEnviron="int_wood";
		AIAvoidStance=1;
		soundHit="wood";
	};
	class planks: GdtStratisThistles
	{
		files="prknaout";
		soundEnviron="wood";
		character="Empty";
		surfaceFriction=1.5;
		restitution=0.2;
		maxSpeedCoef=1;
		rough=0.050000001;
		dust=0.15000001;
		lucidity=0.30000001;
		grassCover=0;
		soundHit="wood";
	};
	class planks_inside: GdtStratisThistles
	{
		files="prknain";
		soundEnviron="int_wood";
		character="Empty";
		AIAvoidStance=1;
		surfaceFriction=1.5;
		restitution=0.2;
		maxSpeedCoef=1;
		rough=0.050000001;
		dust=0.15000001;
		lucidity=0.30000001;
		grassCover=0;
		soundHit="wood";
	};
	class grid: steel
	{
		files="rost*";
		character="Empty";
	};
	class rubble: GdtRubble
	{
		files="sterk*";
		character="Empty";
	};
	class BuildingRubble: GdtRubble
	{
		files="sutiny*";
		character="Empty";
	};
	class tiling: concrete
	{
		files="tasky*";
		soundEnviron="tiling";
		character="Empty";
		AIAvoidStance=1;
	};
	class wavyMetal: steel
	{
		files="vlnityplech*";
		character="Empty";
		soundEnviron="wavymetal";
	};
	class GdtVRsurface01: Default
	{
		access=2;
		files="gdt_vr_*";
		character="Empty";
		soundEnviron="virtual";
		soundHit="soft_ground";
		rough=0.0099999998;
		maxSpeedCoef=1;
		dust=0;
		lucidity=0.30000001;
		grassCover=0;
		impact="hitVirtual";
		maxClutterColoringCoef=1.35;
	};
	class surf_metal: steel
	{
		files="surf_metal*";
		soundEnviron="metal";
		character="Empty";
	};
	class surf_roadconcrete: GdtConcrete
	{
		files="surf_roadconcrete*";
		soundEnviron="concrete";
		character="Empty";
	};
	class surf_roaddirt: GdtDirt
	{
		files="surf_roaddirt*";
		soundEnviron="dirt";
		character="Empty";
	};
	class surf_roadtarmac: road
	{
		files="surf_roadtarmac*";
		soundEnviron="gravel";
		character="Empty";
	};
	class surf_rooftiles: tiling
	{
		files="surf_rooftiles*";
		soundEnviron="tiling";
		character="Empty";
	};
	class surf_rooftin: tiling
	{
		files="surf_rooftin*";
		soundEnviron="int_tiles";
		character="Empty";
	};
	class surf_wood: GdtForestPine
	{
		files="surf_wood*";
		soundEnviron="wood";
		character="Empty";
		soundHit="wood";
	};
	class surfint_concrete: GdtConcrete
	{
		files="surfint_concrete*";
		soundEnviron="int_concrete";
		character="Empty";
		AIAvoidStance=1;
	};
	class surfint_metal: steel
	{
		files="surfint_metal*";
		soundEnviron="int_metal";
		character="Empty";
	};
	class surfint_tiles: tiling
	{
		files="surfint_tiles*";
		soundEnviron="int_tiles";
		character="Empty";
	};
	class surfint_wood: GdtForestPine
	{
		files="surfint_wood*";
		soundEnviron="int_wood";
		character="Empty";
		AIAvoidStance=1;
		soundHit="wood";
	};
	class road_exp: road
	{
		files="surface_road*";
	};
	class sand_exp: sand
	{
		files="surface_sand*";
	};
	class SurfRoadDirt_exp: SurfRoadDirt
	{
		files="surf_exp_roaddirt_*";
		soundEnviron="dirt_exp";
		impact="HitGroundRed";
		dust=0.2;
	};
	class SurfRoadConcrete_exp: SurfRoadConcrete
	{
		files="surf_exp_roadconcrete_*";
		soundEnviron="concrete_exp";
	};
	class SurfRoadTarmac_exp: SurfRoadTarmac
	{
		files="surf_exp_roadtarmac_*";
		soundEnviron="asphalt_exp";
	};
	class SurfTrailDirt_exp: Default
	{
		access=2;
		files="surf_exp_traildirt_*";
		character="Empty";
		soundEnviron="dirt_exp";
		soundHit="hard_ground";
		rough=0.050000001;
		dust=0.02;
		lucidity=1;
		maxSpeedCoef=0.94999999;
		impact="hitGroundHard";
		surfaceFriction=1.4;
		restitution=0.19;
	};
	class concrete_exp: concrete
	{
		files="surface_concrete";
		soundEnviron="concrete_exp";
	};
	class concrete_in_exp: concrete
	{
		files="surface_concrete_in";
		soundEnviron="int_concrete_exp";
		AIAvoidStance=1;
	};
	class concrete_hall_exp: concrete
	{
		files="surface_concrete_hall";
		soundEnviron="int_concrete_exp";
	};
	class floor_exp: floor
	{
		files="surface_floor";
		soundEnviron="pavement_exp";
	};
	class floor_in_exp: floor
	{
		files="surface_floor_in";
		soundEnviron="int_pavement_exp";
		AIAvoidStance=1;
	};
	class stones_exp: stones
	{
		files="surface_stones";
		soundEnviron="stones_exp";
	};
	class planks_in_exp: woodenFloor
	{
		files="surface_planks_in";
		soundEnviron="int_solidwood_exp";
		AIAvoidStance=1;
	};
	class planks_exp: planks
	{
		files="surface_planks";
		soundEnviron="softwood_exp";
	};
	class softwood_in_exp: parquet
	{
		files="surface_parquet";
		soundEnviron="int_softwood_exp";
		AIAvoidStance=1;
	};
	class steel_exp: steel
	{
		files="surface_steel";
		soundEnviron="steel_exp";
	};
	class metalPlate_exp: metalPlate
	{
		files="surface_plate";
		soundEnviron="metalplate_exp";
	};
	class metalPlatePressed_exp: metalPlate
	{
		files="surface_plate_pressed";
		soundEnviron="metalplatepressed_exp";
	};
	class metalPlate_in_exp: metalPlate
	{
		files="surface_plate_in";
		soundEnviron="int_metalplate_exp";
		AIAvoidStance=1;
	};
	class grid_exp: grid
	{
		files="surface_grid";
		soundEnviron="gridmetal_exp";
	};
	class wavyMetal_exp: wavyMetal
	{
		files="surface_wavy_metal";
		soundEnviron="wavymetal_exp";
	};
	class carpet_exp: carpet
	{
		files="surface_carpet";
		soundEnviron="int_carpet_exp";
	};
	class carpet_in_exp: carpet_inside
	{
		files="surface_carpet_in";
		soundEnviron="int_carpet_exp";
	};
	class mat_in_exp: carpet_inside
	{
		files="surface_mat_in";
		soundEnviron="int_mat_exp";
	};
	class mud_exp: mud
	{
		files="surface_mud";
		soundEnviron="mud_exp";
	};
	class straw_exp: mud
	{
		files="surface_straw";
		soundEnviron="straw_exp";
	};
	class cardboard_exp: cardboard
	{
		files="surface_cardboard";
		soundEnviron="dirt_exp";
	};
	class lino_in_exp: lino
	{
		files="surface_lino_in";
		soundEnviron="int_lino_exp";
		AIAvoidStance=1;
	};
	class lino_exp: lino
	{
		files="surface_lino";
		soundEnviron="lino_exp";
	};
	class roof_tiles_exp: tiling
	{
		files="surface_roof_tiles";
		soundEnviron="rooftiles_exp";
	};
	class trash_exp: trash
	{
		files="surface_trash*";
	};
	class rubble_exp: rubble
	{
		files="surface_rubble*";
		soundEnviron="gravel_exp";
	};
	class BuildingRubble_exp: BuildingRubble
	{
		files="surface_building_rubble*";
		soundEnviron="gravel_exp";
	};
	class GdtForestMalden: Default
	{
		access=2;
		files="gdt_forest_malden_*";
		character="MaldenForestClutter";
		soundEnviron="drygrass";
		soundHit="foliage";
		rough=0.12;
		dust=0.30000001;
		lucidity=3.5;
		grassCover=0.039999999;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		maxClutterColoringCoef=1.35;
	};
	class GdtGrassShort: Default
	{
		access=2;
		files="gdt_grass_short_*";
		character="GrassShortGroup";
		soundEnviron="grass_exp";
		soundHit="foliage";
		rough=0.079999998;
		dust=0.15000001;
		lucidity=4;
		grassCover=0.15000001;
		maxClutterColoringCoef=1;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		AIAvoidStance=1;
	};
	class GdtGrassTall: Default
	{
		access=2;
		files="gdt_grass_tall_*";
		character="GrassTallGroup";
		soundEnviron="grasstall_exp";
		soundHit="foliage";
		rough=0.2;
		dust=0.15000001;
		lucidity=4;
		grassCover=0.34999999;
		maxClutterColoringCoef=1.0599999;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		AIAvoidStance=2;
	};
	class GdtGrassLong: Default
	{
		access=2;
		files="gdt_grass_long_*";
		character="Empty";
		soundEnviron="grasstall_exp";
		soundHit="foliage";
		rough=0.2;
		dust=0.15000001;
		lucidity=4;
		grassCover=0.34999999;
		maxClutterColoringCoef=1.5;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
		AIAvoidStance=2;
	};
	class GdtVolcanoBeach: Default
	{
		access=2;
		files="gdt_vbeach_*";
		character="Empty";
		soundEnviron="sand_exp";
		soundHit="soft_ground";
		rough=0.1;
		dust=0.2;
		lucidity=1.25;
		grassCover=0;
		maxClutterColoringCoef=1.5;
		impact="hitGroundSoft";
		surfaceFriction=1;
		restitution=0.050000001;
		maxSpeedCoef=1;
	};
	class GdtSeabedExp: Default
	{
		access=2;
		files="gdt_seabedexp_*";
		character="SeabedExpGroup";
		soundEnviron="seabed_exp";
		soundHit="hard_ground";
		rough=0.15000001;
		dust=0.75;
		lucidity=150;
		grassCover=0;
		maxClutterColoringCoef=1.5;
		impact="hitGroundHard";
		surfaceFriction=1;
		restitution=0.050000001;
		maxSpeedCoef=1;
	};
	class GdtRedDirt: Default
	{
		access=2;
		files="gdt_reddirt_*";
		character="RedDirtGroup";
		soundEnviron="dirt_exp";
		soundHit="soft_ground";
		rough=0.090000004;
		dust=0.2;
		lucidity=1;
		grassCover=0.050000001;
		maxClutterColoringCoef=1.02;
		impact="hitGroundRed";
		surfaceFriction=1.4;
		restitution=0.19;
		maxSpeedCoef=1;
	};
	class GdtAsphalt: Default
	{
		access=2;
		files="gdt_asphalt_*";
		character="Empty";
		soundEnviron="asphalt_exp";
		soundHit="concrete";
		rough=0.050000001;
		dust=0.050000001;
		lucidity=0.029999999;
		grassCover=0;
		maxClutterColoringCoef=1.5;
		impact="hitConcrete";
		surfaceFriction=2;
		restitution=0.2;
	};
	class GdtField: Default
	{
		access=2;
		files="gdt_field_*";
		character="Empty";
		soundEnviron="dirt_exp";
		soundHit="soft_ground";
		rough=0.090000004;
		dust=0.2;
		lucidity=1;
		grassCover=0.050000001;
		maxClutterColoringCoef=1.5;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
	};
	class GdtForest: Default
	{
		access=2;
		files="gdt_forest_*";
		character="RainForestGroup";
		soundEnviron="forest_exp";
		soundHit="foliage";
		rough=0.12;
		dust=0;
		lucidity=3.5;
		grassCover=0.1;
		maxClutterColoringCoef=1.05;
		impact="hitGroundSoft";
		surfaceFriction=1.2;
		restitution=0.15000001;
		maxSpeedCoef=0.85000002;
	};
	class GdtVolcano: Default
	{
		access=2;
		files="gdt_volcano_*";
		character="VolcanoGroup";
		soundEnviron="dirt_exp";
		soundHit="soft_ground";
		rough=0.090000004;
		dust=0.5;
		lucidity=1;
		grassCover=0.050000001;
		maxClutterColoringCoef=1;
		impact="hitGroundSoft";
		surfaceFriction=1.4;
		restitution=0.19;
		maxSpeedCoef=1;
	};
	class GdtCliff: Default
	{
		access=2;
		files="gdt_rock_*";
		character="CliffGroup";
		soundEnviron="stones_exp";
		soundHit="concrete";
		rough=0.2;
		dust=0.050000001;
		lucidity=1;
		grassCover=0;
		maxClutterColoringCoef=1.3;
		impact="hitGroundHard";
		surfaceFriction=1.8;
		restitution=0.25;
		maxSpeedCoef=0.86000001;
	};
	class SurfRoadDirt_Enoch: SurfRoadDirt_exp
	{
		files="mud_gravel_*";
	};
	class SurfRoadTarmac1_Enoch: SurfRoadTarmac_exp
	{
		files="asf1_dashedline_*";
	};
	class SurfRoadTarmac2_Enoch: SurfRoadTarmac_exp
	{
		files="asf2_clear_*";
	};
	class SurfRoadTarmac3_Enoch: SurfRoadTarmac_exp
	{
		files="asf3_clear_*";
	};
	class SurfTrailDirt_Enoch: SurfTrailDirt_exp
	{
		files="path_narrow_forest_01_*";
	};
	class GdtKLDirt: Default
	{
		access=2;
		files="gdt_dirt*";
		character="empty";
		soundEnviron="gravel";
		soundHit="soft_ground";
		impact="hitGroundSoft";
		rough=0.2;
		maxSpeedCoef=0.94999999;
		dust=0.2;
		lucidity=0.30000001;
		grassCover=0;
		maxClutterColoringCoef=1.15;
	};
	class GdtKLGrass1: Default
	{
		access=2;
		files="gdt_engrass1*";
		character="KLGrass1";
		soundEnviron="grass";
		soundHit="foliage";
		impact="hitGroundSoft";
		rough=0.079999998;
		maxSpeedCoef=1;
		dust=0.15000001;
		lucidity=1.25;
		grassCover=0.40000001;
		maxClutterColoringCoef=1.35;
	};
	class GdtKLGrass2: Default
	{
		access=2;
		files="gdt_engrass2*";
		character="KLGrass2";
		soundEnviron="drygrass";
		soundHit="foliage";
		impact="hitGroundSoft";
		rough=0.2;
		maxSpeedCoef=1;
		dust=0.15000001;
		lucidity=1.25;
		grassCover=0.94999999;
		maxClutterColoringCoef=1.35;
		AIAvoidStance=2;
	};
	class GdtKLForestCon: Default
	{
		access=2;
		files="gdt_enforestcon*";
		character="KLForestCon";
		soundEnviron="forest_exp";
		soundHit="soft_ground";
		impact="hitGroundSoft";
		rough=0.079999998;
		maxSpeedCoef=1;
		dust=0.1;
		lucidity=4;
		grassCover=0.5;
		maxClutterColoringCoef=1.35;
		AIAvoidStance=2;
	};
	class GdtKLForestDec: Default
	{
		access=2;
		files="gdt_enforestdec*";
		character="KLForestDec";
		soundEnviron="forest_exp";
		soundHit="foliage";
		impact="hitGroundSoft";
		rough=0.079999998;
		maxSpeedCoef=1;
		dust=0.1;
		lucidity=4;
		grassCover=0.5;
		maxClutterColoringCoef=1.25;
		AIAvoidStance=2;
	};
	class GdtKlSoil: Default
	{
		access=2;
		files="gdt_ensoil*";
		character="KLSoil";
		soundEnviron="dirt";
		soundHit="soft_ground";
		rough=0.15000001;
		maxSpeedCoef=0.85000002;
		dust=0.050000001;
		lucidity=1.5;
		grassCover=0;
		impact="hitGroundHard";
		surfaceFriction=1.7;
		maxClutterColoringCoef=1.2;
	};
	class GdtKlTarmac: Default
	{
		access=2;
		files="gdt_entarmac*";
		character="Empty";
		soundEnviron="concrete";
		soundHit="concrete";
		rough=0.050000001;
		maxSpeedCoef=1;
		dust=0.050000001;
		lucidity=0.30000001;
		grassCover=0;
		impact="hitConcrete";
		maxClutterColoringCoef=1;
	};
	class GdtKlWeatheredTarmac: Default
	{
		access=2;
		files="gdt_enweatheredtarmac*";
		character="KlWeatheredTarmac";
		soundEnviron="concrete";
		soundHit="concrete";
		rough=0.050000001;
		maxSpeedCoef=1;
		dust=0.050000001;
		lucidity=0.30000001;
		grassCover=0;
		impact="hitConcrete";
		maxClutterColoringCoef=1;
	};
	class GdtKLCobblestone: Default
	{
		access=2;
		files="gdt_encobblestone*";
		character="Empty";
		soundEnviron="concrete";
		soundHit="concrete";
		rough=0.050000001;
		maxSpeedCoef=1;
		dust=0.050000001;
		lucidity=0.30000001;
		grassCover=0;
		impact="hitConcrete";
		maxClutterColoringCoef=1;
	};
	class GdtKlField: Default
	{
		access=2;
		files="gdt_enfield*";
		character="KLField";
		soundEnviron="grass";
		soundHit="foliage";
		rough=0.050000001;
		maxSpeedCoef=1;
		dust=0.15000001;
		lucidity=1.25;
		grassCover=0.60000002;
		impact="hitGroundHard";
		maxClutterColoringCoef=1.08;
		AIAvoidStance=2;
	};
	class GdtKlStubble: Default
	{
		access=2;
		files="gdt_enstubble*";
		character="KLStubble";
		soundEnviron="grass";
		soundHit="foliage";
		rough=0.050000001;
		maxSpeedCoef=1;
		dust=0.15000001;
		lucidity=1.25;
		grassCover=0.60000002;
		impact="hitGroundHard";
		maxClutterColoringCoef=1.08;
	};
};
class CfgAmmo
{
	class MissileBase;
	class RocketBase;
	class R_MRAAWS_HEAT_F: RocketBase
	{
		SoundSetExplosion[]=
		{
			"RocketsLight_Exp_SoundSet",
			"RocketsLight_Tail_SoundSet",
			"Explosion_Debris_SoundSet"
		};
	};
	class M_SPG9_HEAT: RocketBase
	{
		SoundSetExplosion[]=
		{
			"RocketsLight_Exp_SoundSet",
			"RocketsLight_Tail_SoundSet",
			"Explosion_Debris_SoundSet"
		};
	};
	class M_Vorona_HEAT: MissileBase
	{
		SoundSetExplosion[]=
		{
			"RocketsMedium_Exp_SoundSet",
			"RocketsMedium_Tail_SoundSet",
			"Explosion_Debris_SoundSet"
		};
	};
	class M_127mm_Firefist_AT: MissileBase
	{
		SoundSetExplosion[]=
		{
			"RocketsMedium_Exp_SoundSet",
			"RocketsMedium_Tail_SoundSet",
			"Explosion_Debris_SoundSet"
		};
	};
	class R_PG32V_F;
	class Default;
	class GrenadeCore;
	class Grenade: Default
	{
		allowAgainstInfantry=1;
		aiAmmoUsageFlags=64;
		soundImpactFoliage1[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_1",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage2[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_2",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage3[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_3",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage4[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_4",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage5[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_5",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage6[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_6",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage7[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_7",
			1.4125376,
			1,
			45
		};
		impactFoliage[]=
		{
			"soundImpactFoliage1",
			0.142857,
			"soundImpactFoliage2",
			0.142857,
			"soundImpactFoliage3",
			0.142857,
			"soundImpactFoliage4",
			0.142857,
			"soundImpactFoliage5",
			0.142857,
			"soundImpactFoliage6",
			0.142857,
			"soundImpactFoliage7",
			0.142857
		};
	};
	class GrenadeBase: GrenadeCore
	{
		allowAgainstInfantry=1;
		aiAmmoUsageFlags="64 + 128";
		soundImpactFoliage1[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_1",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage2[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_2",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage3[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_3",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage4[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_4",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage5[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_5",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage6[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_6",
			1.4125376,
			1,
			45
		};
		soundImpactFoliage7[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grassdry_7",
			1.4125376,
			1,
			45
		};
		impactFoliage[]=
		{
			"soundImpactFoliage1",
			0.142857,
			"soundImpactFoliage2",
			0.142857,
			"soundImpactFoliage3",
			0.142857,
			"soundImpactFoliage4",
			0.142857,
			"soundImpactFoliage5",
			0.142857,
			"soundImpactFoliage6",
			0.142857,
			"soundImpactFoliage7",
			0.142857
		};
	};
	class R_TBG32V_F: R_PG32V_F
	{
		allowAgainstInfantry=1;
		aiAmmoUsageFlags="64 + 128";
	};
	class R_MRAAWS_HE_F: R_MRAAWS_HEAT_F
	{
		allowAgainstInfantry=1;
		aiAmmoUsageFlags="64 + 128";
	};
	class M_Vorona_HE: M_Vorona_HEAT
	{
		allowAgainstInfantry=1;
		aiAmmoUsageFlags="64 + 128";
	};
	class M_70mm_SAAMI: MissileBase
	{
		effectsMissile="FX_Missile_AA";
	};
	class M_Titan_AA: MissileBase
	{
		effectsMissile="FX_Missile_AA";
	};
	class M_Air_AA: MissileBase
	{
		effectsMissile="FX_Missile_AA";
	};
};
class CfgSoundCurves
{
	class vehicleEngineAttenuationCurve
	{
		points[]=
		{
			{0,1},
			{0.0099999998,1},
			{0.035,0.80000001},
			{0.085000001,0.60000002},
			{0.14,0.5},
			{0.22,0.36000001},
			{0.32499999,0.2},
			{0.44999999,0.079999998},
			{0.69999999,0.039999999},
			{1,0}
		};
	};
	class RainPlantsAttenuationCurve
	{
		points[]=
		{
			{0,1},
			{0.1,1},
			{0.2,1},
			{0.30000001,1},
			{0.40000001,0.5},
			{0.5,0.25},
			{0.60000002,0.12},
			{0.69999999,0.059999999},
			{0.80000001,0.059999999},
			{0.89999998,0.059999999},
			{1,0}
		};
	};
	class animals_new_Curve
	{
		points[]=
		{
			{0,1},
			{0.050000001,0.91500002},
			{0.1,0.81940001},
			{0.15000001,0.7015},
			{0.2,0.625},
			{0.25,0.57249999},
			{0.30000001,0.435},
			{0.34999999,0.30720001},
			{0.40000001,0.2561},
			{0.44999999,0.1697},
			{0.5,0.1066},
			{0.60000002,0.087499999},
			{0.69999999,0.054400001},
			{0.80000001,0.045000002},
			{0.89999998,0.0381},
			{1,0}
		};
	};
	class defaultAnimalAttenuationCurve
	{
		points[]=
		{
			{0,1},
			{0.0099999998,0.69999999},
			{0.035,0.44999999},
			{0.085000001,0.25},
			{0.14,0.15000001},
			{0.22,0.090000004},
			{0.32499999,0.050000001},
			{0.44999999,0.02},
			{0.69999999,0.0099999998},
			{1,0}
		};
	};
	class animalAttenuationCurve: defaultAnimalAttenuationCurve
	{
	};
	class CreakAttenuationCurve
	{
		points[]=
		{
			{0,1},
			{0.1,1},
			{0.2,1},
			{0.30000001,1},
			{0.40000001,0.44400001},
			{0.5,0.25},
			{0.60000002,0.16},
			{0.69999999,0.081},
			{0.80000001,0.063000001},
			{0.89999998,0.044},
			{1,0}
		};
	};
	class birdsVolumeCurve
	{
		points[]=
		{
			{0,1},
			{0.1,1},
			{0.2,0.44400001},
			{0.30000001,0.25},
			{0.40000001,0.16},
			{0.5,0.111},
			{0.60000002,0.081},
			{0.69999999,0.059999999},
			{0.80000001,0.045000002},
			{0.89999998,0.035},
			{1,0}
		};
	};
	class insectsVolumeCurve
	{
		points[]=
		{
			{0,1},
			{0.1,1},
			{0.2,0.44400001},
			{0.30000001,0.25},
			{0.40000001,0.16},
			{0.5,0.111},
			{0.60000002,0.081},
			{0.69999999,0.063000001},
			{0.80000001,0.048999999},
			{0.89999998,0.039999999},
			{1,0}
		};
	};
	class insectsDayVolumeCurve
	{
		points[]=
		{
			{0,0.5},
			{0.1,0.5},
			{0.2,0.25},
			{0.30000001,0.111},
			{0.40000001,0.063000001},
			{0.5,0.028000001},
			{0.60000002,0.02},
			{0.69999999,0.016000001},
			{0.80000001,0.012},
			{0.89999998,0.0099999998},
			{1,0}
		};
	};
	class objectTransitionCurve
	{
		points[]=
		{
			{0,1},
			{0.1,0.89999998},
			{0.2,0.80000001},
			{0.30000001,0.69999999},
			{0.40000001,0.60000002},
			{0.5,0.5},
			{0.60000002,0.40000001},
			{0.69999999,0.30000001},
			{0.80000001,0.2},
			{0.89999998,0.1},
			{1,0}
		};
	};
	class WindAttenuationCurve
	{
		points[]=
		{
			{0,1},
			{0.1,1},
			{0.2,1},
			{0.30000001,1},
			{0.40000001,0.44400001},
			{0.5,0.25},
			{0.60000002,0.16},
			{0.69999999,0.081},
			{0.80000001,0.063000001},
			{0.89999998,0.044},
			{1,0}
		};
	};
};
class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons
{
	class MissileLauncher;
	class arifle_AK12_base_F;
	class Launcher_Base_F;
	class Rifle_Long_Base_F;
	class Rifle_Base_F;
	class CannonCore;
	class mortar_155mm_AMOS: CannonCore
	{
		class GunParticles
		{
			class Effect1
			{
				effectName="ArtilleryFired1";
				positionName="Usti hlavne3";
				directionName="Konec hlavne3";
			};
			class Effect2
			{
				effectName="ArtilleryFiredL";
				positionName="Usti hlavne3";
				directionName="Usti hlavne b";
			};
			class Effect3
			{
				effectName="ArtilleryFiredR";
				positionName="Usti hlavne3";
				directionName="Usti hlavne b";
			};
		};
	};
	class arifle_CTAR_base_F: Rifle_Base_F
	{
		reloadMagazineSound[]=
		{
			"a3\sounds_f_exp\arsenal\weapons\rifles\car_95\car_95_reload",
			1,
			1,
			10
		};
	};
	class launch_RPG7_F: Launcher_Base_F
	{
		recoil="recoil_rpg7";
	};
	class MMG_02_base_F: Rifle_Long_Base_F
	{
		recoil="recoil_mmg_02";
	};
	class arifle_AK12U_base_F: arifle_AK12_base_F
	{
		recoil="recoil_ak12u";
	};
	class arifle_MSBS65_base_F: Rifle_Base_F
	{
		class Single: Mode_SemiAuto
		{
			class SilencedSound
			{
				soundSetShot[]+=
				{
					"Msbs65_01_silencerTail_SoundSet"
				};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			class SilencedSound
			{
				soundSetShot[]+=
				{
					"Msbs65_01_silencerTail_SoundSet"
				};
			};
		};
	};
	class arifle_Katiba_Base_F: Rifle_Base_F
	{
		class FullAuto: Mode_FullAuto
		{
			recoil="recoil_auto_ktb";
			recoilProne="recoil_auto_prone_ktb";
		};
	};
};
class ArtilleryFired1
{
	class Smoke1;
};
class ArtilleryFiredL: ArtilleryFired1
{
	class Smoke1: Smoke1
	{
		type="ArtilleryFiredL";
	};
};
class ArtilleryFiredR: ArtilleryFired1
{
	class Smoke1: Smoke1
	{
		type="ArtilleryFiredR";
	};
};
class CfgDistanceFilters
{
	class LowIntensityDistanceFilter
	{
		type="lowPassFilter";
		minCutoffFrequency=5000;
		qFactor=1;
		innerRange=10;
		range=1000;
		powerFactor=32;
	};
};
class CfgVideoOptions
{
	class CloudQuality
	{
		class Extreme
		{
			value=192;
		};
	};
};
class CfgMovesBasic
{
	class Default
	{
		idle = "";
	};

	class StandBase;
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class SprintCivilBaseDf;
		class TransAnimBase;

		class AidlPercMstpSrasWpstDnon_G0S;
		class AovrPercMstpSrasWpstDf: AidlPercMstpSrasWpstDnon_G0S
		{
			connectTo[] =
			{
				"AmovPercMstpSrasWpstDnon", 0.04
			};
		};

		class AmovPercMevaSnonWnonDf: SprintCivilBaseDf
		{
			connectTo[] = { };
			interpolateTo[] =
			{
				"AmovPercMsprSnonWnonDf_AmovPpneMstpSnonWnonDnon", 0.02, //change this into interp
				"AmovPercMrunSnonWnonDf", 0.02,
				"AmovPercMstpSnonWnonDnon", 0.06,
				"AmovPercMwlkSnonWnonDf", 0.025,
				"AmovPercMevaSnonWnonDfl", 0.02,
				"AmovPercMevaSnonWnonDfr", 0.02,
				"AmovPknlMevaSnonWnonDf", 0.02,
				"Unconscious", 0.02
			};
		};

		class AmovPercMstpSlowWrflDnon: StandBase
		{
			connectTo[] =
			{
				"AmovPercMstpSlowWrflDnon", 0.02,
				"AmovPercMstpSlowWrflDnon_AmovPknlMstpSlowWrflDnon", 0.02,
				"AmovPercMstpSlowWrflDnon_AmovPpneMstpSrasWrflDnon", 0.02,
				"AmovPercMstpSlowWrflDnon_AmovPercMstpSrasWrflDnon", 0.01,
				"AmovPercMstpSlowWrflDnon_SaluteIn", 0.1,
				"AmovPercMstpSrasWrflDnon_SaluteIn", 0.15,
				"AmovPercMstpSlowWrflDnon_AmovPsitMstpSlowWrflDnon", 0.1,
				"AmovPercMstpSlowWrflDnon_AmovPsitMstpSrasWrflDnon", 0.1,
				"LadderRifleOn", 1,
				"AmovPercMstpSnonWnonDnon_AcinPknlMwlkSnonWnonDb_1", 0.1,
				"Acts_TreatingWounded_in", 0.0001,
				"Acts_SignalToCheck", 0.001,
				"Acts_AidlPercMstpSlowWrflDnon_pissing", 0.001,
				"AmovPercMstpSrasWrflDnon_AmovPercMstpSrasWlnrDnon", 0.02,
				"AmovPercMstpSrasWrflDnon_AmovPercMstpSrasWpstDnon", 0.02,
				"Acts_RifleLowStand_Default", 1
			};
		};

		class AmovPercMstpSrasWpstDnon;
		class AmovPknlMstpSrasWpstDnon: AmovPercMstpSrasWpstDnon
		{
			interpolateTo[] =
			{
				"AidlPknlMstpSrasWpstDnon_AI", 0.02,
				"AinvPknlMstpSlayWpstDnon_medicIn", 0.02,
				"AinvPknlMstpSlayWpstDnon_medicOtherIn", 0.02,
				"AmovPknlMstpSrasWpstDnon_turnL", 0.02,
				"AmovPknlMstpSrasWpstDnon_turnR", 0.02,
				"AmovPknlMwlkSrasWpstDf", 0.02,
				"AmovPknlMwlkSrasWpstDfl", 0.02,
				"AmovPknlMwlkSrasWpstDl", 0.02,
				"AmovPknlMwlkSrasWpstDbl", 0.02,
				"AmovPknlMwlkSrasWpstDb", 0.02,
				"AmovPknlMwlkSrasWpstDbr", 0.02,
				"AmovPknlMwlkSrasWpstDr", 0.02,
				"AmovPknlMwlkSrasWpstDfr", 0.02,
				"AmovPknlMrunSrasWpstDf", 0.02,
				"AmovPknlMrunSrasWpstDfl", 0.02,
				"AmovPknlMrunSrasWpstDl", 0.02,
				"AmovPknlMrunSrasWpstDbl", 0.02,
				"AmovPknlMrunSrasWpstDb", 0.02,
				"AmovPknlMrunSrasWpstDbr", 0.02,
				"AmovPknlMrunSrasWpstDr", 0.02,
				"AmovPknlMrunSrasWpstDfr", 0.02,
				"Unconscious", 0.02,
				"AovrPercMstpSrasWpstDf", 0.02,
				"AmovPercMstpSrasWpstDnon_AcinPknlMwlkSnonWpstDb_2", 0.2,
				"AmovPknlMstpSrasWpstDnon_relax", 0.2,
				"AinvPercMstpSrasWrflDnon", 0.05,
				"AmovPknlMstpSrasWpstDnon_AinvPknlMstpSrasWpstDnon", 0.02,
				"AmovPknlMstpSrasWpstDnon_AinvPknlMstpSrasWpstDnon_Putdown", 0.02,
				"AmovPknlMstpSrasWpstDnon_AmovPercMstpSrasWpstDnon", 0.02,
				"AmovPknlMstpSrasWpstDnon_AmovPercMsprSrasWpstDf", 0.01,
				"AmovPknlMstpSrasWpstDnon_AmovPpneMstpSrasWpstDnon", 0.02,
				"AfalPknlMstpSrasWpstDnon", 0.025,
				"Campaign_Base", 0.01,
				"AmovPknlMlmpSrasWpstDfl", 0.05,
				"AmovPknlMlmpSrasWpstDf", 0.05,
				"AmovPknlMlmpSrasWpstDl", 0.05,
				"AmovPknlMlmpSrasWpstDbl", 0.05,
				"AmovPknlMlmpSrasWpstDb", 0.05,
				"AmovPknlMlmpSrasWpstDbr", 0.05,
				"AmovPknlMlmpSrasWpstDr", 0.05,
				"AmovPknlMlmpSrasWpstDfr", 0.05,
				"UnconsciousMedicFromPistolKneel", 0.2
			};
		};

		class AmovPknlMstpSlowWrflDnon;
		class AmovPknlMstpSrasWrflDnon: AmovPknlMstpSlowWrflDnon
		{
			connectTo[] =
			{
				"AidlPknlMstpSlowWrflDnon_AI", 0.1,
				"AmovPknlMstpSrasWrflDnon", 0.02,
				"WeaponMagazineReloadKneel", 0.1,
				"AmovPknlMstpSrasWrflDnon_AmovPknlMstpSlowWrflDnon", 0.02,
				"AmovPknlMstpSrasWrflDnon_AmovPknlMstpSrasWpstDnon", 0.02,
				"AmovPknlMstpSrasWrflDnon_AmovPknlMstpSrasWlnrDnon", 0.02,
				"AmovPknlMstpSrasWrflDnon_AwopPknlMstpSoptWbinDnon", 0.02,
				"AmovPknlMstpSrasWrflDnon_AinvPknlMstpSrasWrflDnon", 0.02,
				"AmovPknlMstpSrasWrflDnon_AmovPknlMstpSnonWnonDnon", 0.02, //change
				"AmovPknlMstpSrasWrflDnon_AinvPknlMstpSrasWrflDnon_Putdown", 0.02,
				"AwopPknlMstpSgthWrflDnon_Start", 0.1,
				"AwopPknlMstpSgthWrflDnon_End", 0.1,
				"AmovPknlMstpSrasWrflDnon_AadjPknlMstpSrasWrflDup", 0.02,
				"AmovPknlMstpSrasWrflDnon_AadjPknlMstpSrasWrflDdown", 0.02,
				"AmovPknlMstpSrasWrflDnon_AadjPknlMstpSrasWrflDleft", 0.02,
				"AmovPknlMstpSrasWrflDnon_AadjPknlMstpSrasWrflDright", 0.02,
				"AmovPknlMstpSrasWrflDnon_AmovPknlMstpSrasWrflDnon_gear", 0.02,
				"AmovPknlMstpSrasWrflDnon_AmovPknlMrunSlowWrflDf", 0.01
			};
			interpolateTo[] =
			{
				"AmovPknlMstpSrasWrflDnon_turnL", 0.02,
				"AmovPknlMstpSrasWrflDnon_turnR", 0.02,
				"AmovPknlMstpSrasWrflDnon_AmovPercMstpSrasWrflDnon", 0.02, //change
				"AmovPknlMstpSrasWrflDnon_AmovPpneMstpSrasWrflDnon", 0.02, //change
				"AidlPknlMstpSrasWrflDnon_AI", 0.02,
				"AinvPknlMstpSnonWrflDnon_AinvPknlMstpSnonWrflDnon_medic", 0.02,
				"AmovPknlMwlkSrasWrflDf", 0.02,
				"AmovPknlMwlkSrasWrflDfl", 0.02,
				"AmovPknlMwlkSrasWrflDl", 0.02,
				"AmovPknlMwlkSrasWrflDbl", 0.02,
				"AovrPercMstpSrasWrflDf", 1.02,
				"AmovPknlMwlkSrasWrflDb", 0.02,
				"AmovPknlMwlkSrasWrflDbr", 0.02,
				"AmovPknlMwlkSrasWrflDr", 0.02,
				"AmovPknlMwlkSrasWrflDfr", 0.02,
				"AmovPknlMrunSrasWrflDf", 0.02,
				"AmovPknlMrunSrasWrflDfl", 0.02,
				"AmovPknlMrunSrasWrflDfr", 0.02,
				"AmovPknlMrunSrasWrflDl", 0.02,
				"AmovPknlMrunSrasWrflDbl", 0.02,
				"AmovPknlMrunSrasWrflDb", 0.02,
				"AmovPknlMrunSrasWrflDbr", 0.02,
				"AmovPknlMrunSrasWrflDr", 0.02,
				"AmovPknlMrunSrasWrflDf_ldst", 0.02,
				"AmovPknlMrunSrasWrflDfl_ldst", 0.02,
				"AmovPknlMrunSrasWrflDl_ldst", 0.02,
				"AmovPknlMrunSrasWrflDbl_ldst", 0.02,
				"AmovPknlMrunSrasWrflDb_ldst", 0.02,
				"AmovPknlMrunSrasWrflDbr_ldst", 0.02,
				"AmovPknlMrunSrasWrflDr_ldst", 0.02,
				"AmovPknlMrunSrasWrflDfr_ldst", 0.02,
				"AmovPknlMevaSrasWrflDr", 0.025,
				"AmovPknlMevaSrasWrflDl", 0.025,
				"AmovPknlMtacSrasWrflDf", 0.02,
				"AmovPknlMtacSrasWrflDfl", 0.02,
				"AmovPknlMtacSrasWrflDl", 0.02,
				"AmovPknlMtacSrasWrflDbl", 0.02,
				"AmovPknlMtacSrasWrflDb", 0.02,
				"AmovPknlMtacSrasWrflDbr", 0.02,
				"AmovPknlMtacSrasWrflDr", 0.02,
				"AmovPknlMtacSrasWrflDfr", 0.02,
				"Unconscious", 0.02,
				"AmovPercMstpSlowWrflDnon_AcinPknlMwlkSlowWrflDb_2", 0.2,
				"ReloadGM6", 0.2,
				"DismountOptic", 0.2,
				"MountOptic", 0.2,
				"MountSide", 0.2,
				"DismountSide", 0.2,
				"AmovPknlMstpSlowWrflDnon_relax", 10.2,
				"AinvPknlMstpSnonWrflDnon_medicUp", 0.2,
				"AinvPknlMstpSlayWrflDnon_medic", 0.05,
				"AinvPknlMstpSlayWrflDnon_medicOther", 0.05,
				"AmovPknlMstpSlowWrflDnon_AmovPknlMstpSrasWrflDnon", 0.02,
				"AmovPercMstpSrasWrflDnon_AmovPknlMstpSrasWrflDnon", 0.02,
				"AfalPknlMstpSrasWrflDnon", 0.025,
				"AinvPknlMstpSnonWrflDr_medic1", 0.05,
				"AinvPknlMstpSnonWrflDr_medic2", 0.05,
				"AinvPknlMstpSnonWrflDr_medic3", 0.05,
				"AinvPknlMstpSnonWrflDr_medic4", 0.05,
				"AinvPknlMstpSnonWrflDr_medic5", 0.05,
				"Campaign_Base", 0.01,
				"AmovPknlMlmpSrasWrflDf", 0.05,
				"AmovPknlMlmpSrasWrflDfl", 0.05,
				"AmovPknlMlmpSrasWrflDl", 0.05,
				"AmovPknlMlmpSrasWrflDbl", 0.05,
				"AmovPknlMlmpSrasWrflDb", 0.05,
				"AmovPknlMlmpSrasWrflDbr", 0.05,
				"AmovPknlMlmpSrasWrflDr", 0.05,
				"AmovPknlMlmpSrasWrflDfr", 0.05,
				"Acts_SupportTeam_Front_StartMove", 1,
				"Acts_SupportTeam_Right_StartMove", 1,
				"Acts_SupportTeam_Left_StartMove", 1,
				"Acts_SupportTeam_Back_StartMove", 1,
				"UnconsciousMedicFromRifleKneel", 0.2
			};
		};
		class AmovPknlMrunSrasWrflDf: AmovPknlMstpSrasWrflDnon
		{
			interpolateTo[] =
			{
				"AmovPercMrunSrasWrflDf", 0.03,
				"AmovPknlMwlkSrasWrflDf", 0.025,
				"AmovPknlMrunSrasWrflDfl", 0.025,
				"AmovPknlMrunSrasWrflDfr", 0.025,
				"AmovPknlMrunSlowWrflDf", 0.025,
				"AmovPknlMevaSrasWrflDf", 0.025,
				"Unconscious", 0.02,
				"AmovPknlMtacSrasWrflDf", 0.02,
				"AmovPknlMstpSrasWrflDnon", 0.03,
				"AmovPknlMstpSlowWrflDnon_relax", 0.1,
				"AmovPercMrunSlowWrflDf_AmovPpneMstpSrasWrflDnon", 0.02
			};
		};

		class AmovPercMstpSnonWnonDnon: StandBase
		{
			mask = "weaponSwitching";
		};
		class AmovPercMrunSnonWnonDf: AmovPercMstpSnonWnonDnon
		{
			delete soundEdge;
		};

		class AmovPknlMstpSnonWnonDnon: AmovPercMstpSnonWnonDnon
		{
			connectTo[] =
			{
				"AmovPknlMstpSnonWnonDnon_gear", 0.02,
				"AmovPercMstpSnonWnonDnon_gear", 0.02,
				"AmovPknlMstpSnonWnonDnon_AmovPknlMstpSrasWlnrDnon", 0.019,
				"AmovPknlMstpSnonWnonDnon_AmovPknlMstpSrasWpstDnon", 0.02,
				"AmovPknlMstpSnonWnonDnon_AmovPknlMstpSrasWrflDnon", 0.02,
				"AmovPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon", 0.02,
				"AmovPknlMstpSnonWnonDnon_AmovPercMsprSnonWnonDf", 0.01,
				"AmovPknlMstpSnonWnonDnon_AmovPpneMstpSnonWnonDnon", 0.02,
				"AmovPknlMstpSnonWnonDnon_AwopPknlMstpSoptWbinDnon", 0.02,
				"AmovPknlMstpSnonWnonDnon", 0.02
			};
		};

		class AmovPpneMstpSnonWnonDnon: AmovPercMstpSnonWnonDnon
		{
			connectTo[] =
			{
				"AmovPpneMstpSnonWnonDnon", 0.02,
				"AmovPpneMstpSnonWnonDnon_AmovPknlMstpSnonWnonDnon", 0.019, //move this to higher priority
				"AmovPpneMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon", 0.02,
				"AmovPpneMstpSnonWnonDnon_AmovPercMsprSnonWnonDf", 0.05,
				"AmovPpneMstpSnonWnonDnon_AmovPpneMstpSrasWrflDnon", 0.01,
				"AmovPpneMstpSnonWnonDnon_AmovPpneMstpSrasWpstDnon", 0.02,
				"AmovPpneMstpSnonWnonDnon_AwopPpneMstpSoptWbinDnon", 0.02,
				"AmovPpneMstpSnonWnonDnon_AmovPpneMevaSnonWnonDl", 0.02,
				"AmovPpneMstpSnonWnonDnon_AmovPpneMevaSnonWnonDr", 0.02,
				"AmovPpneMstpSnonWnonDnon_AmovPsitMstpSnonWnonDnon_ground", 0.1,
				"AwopPpneMstpSgthWnonDnon_start", 0.1,
				"AmovPpneMstpSnonWnonDnon_healed", 0.02,
				"AmovPpneMstpSnonWnonDnon_injured", 0.1
			};
		};

		class AmovPercMstpSlowWrflDnon_AmovPknlMstpSlowWrflDnon: AmovPknlMstpSlowWrflDnon
		{
			interpolateTo[] +=
			{
				"AmovPknlMstpSlowWrflDnon_AmovPercMstpSlowWrflDnon", 0.0098
			};
			mask = "weaponSwitching";
			soundOverride = "adjust_stand_to_kneel";
			speed = 1.8181;
		};
		class AmovPknlMstpSlowWrflDnon_AmovPercMstpSlowWrflDnon: AmovPercMstpSlowWrflDnon
		{
			interpolateTo[] +=
			{
				"AmovPercMstpSlowWrflDnon_AmovPknlMstpSlowWrflDnon", 0.0098
			};
			mask = "weaponSwitching";
			soundOverride = "adjust_kneel_to_stand";
			speed = 1.8181;
		};

		class AmovPpneMstpSrasWrflDnon_AmovPercMsprSlowWrflDf: TransAnimBase
		{
			connectTo[] = { };
			interpolateTo[] =
			{
				"AmovPpneMstpSrasWrflDnon_AmovPercMsprSlowWrflDf_2", 0.005,
				"Unconscious", 0.02
			};
			interpolationSpeed = 10;
			leftHandIKCurve[] = { 0, 0, 0.25, 0, 1, 1 };
			minPlayTime = 0.7;
			weaponIK = 1;
		};
		class AmovPpneMstpSrasWrflDnon_AmovPercMsprSlowWrflDf_2: AmovPpneMstpSrasWrflDnon_AmovPercMsprSlowWrflDf
		{
			interpolateTo[] =
			{
				"AmovPercMevaSrasWrflDf", 0.005,
				"AmovPercMevaSrasWrflDfl", 0.005,
				"AmovPercMevaSrasWrflDfr", 0.005,
				"Unconscious", 0.02,
				"AmovPercMstpSlowWrflDnon", 0.05,
				"AmovPercMsprSlowWrflDf_AmovPpneMstpSrasWrflDnon", 0.02
			};
			interpolationSpeed = 4;
			leftHandIKCurve[] = { 1 };
			minPlayTime = 0;
			speed = 0.5;
		};

		//fix getting up when down
		class AmovPpneMstpSrasWrflDnon_injured;
		class AinjPpneMstpSnonWrflDnon: AmovPpneMstpSrasWrflDnon_injured
		{
			interpolateTo[] =
			{
				"UnconsciousReviveDefault", 0.02,
				"Unconscious", 0.02
			};
		};

		class AmovPpneMstpSnonWnonDnon_injured;
		class AinjPpneMstpSnonWnonDnon: AmovPpneMstpSnonWnonDnon_injured
		{
			interpolateTo[] =
			{
				"Unconscious", 0.02,
				"AinjPpneMrunSnonWnonDb_grab", 0.1,
				"UnconsciousReviveDefault", 0.02
			};
		};

		//change connect to interp
		class AmovPercMsprSnonWnonDf_AmovPpneMstpSnonWnonDnon_2: AmovPpneMstpSnonWnonDnon
		{
			connectTo[] = { };
			interpolateTo[] =
			{
				"AmovPpneMstpSnonWnonDnon", 0.02
			};
			minPlayTime = 0.9;
		};

		//fix crouched non-pistol looping
		class AmovPknlMstpSrasWpstDnon_AmovPknlMstpSnonWnonDnon;
		class AmovPknlMstpSnonWnonDnon_AmovPknlMstpSrasWpstDnon: AmovPknlMstpSrasWpstDnon_AmovPknlMstpSnonWnonDnon
		{
			actions = "PistolKneelActions";
		};

		class AmovPknlMstpSrasWrflDnon_AmovPknlMstpSnonWnonDnon: AmovPknlMstpSnonWnonDnon
		{
			connectTo[] =
			{
				"AmovPknlMstpSnonWnonDnon", 0.019,
				"AmovPknlMstpSnonWnonDnon_gear", 0.02,
				"AmovPercMstpSnonWnonDnon_gear", 0.02,
				"AmovPknlMstpSnonWnonDnon_AmovPknlMstpSrasWlnrDnon", 0.019,
				"AmovPknlMstpSnonWnonDnon_AmovPknlMstpSrasWpstDnon", 0.02,
				"AmovPknlMstpSnonWnonDnon_AmovPknlMstpSrasWrflDnon", 0.02,
				"AmovPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon", 0.02,
				"AmovPknlMstpSnonWnonDnon_AmovPercMsprSnonWnonDf", 0.02,
				"AmovPknlMstpSnonWnonDnon_AmovPpneMstpSnonWnonDnon", 0.02,
				"AmovPknlMstpSnonWnonDnon_AwopPknlMstpSoptWbinDnon", 0.02
			};
		};

		class HubTemplate_Briefing;
		class HubBriefing_ext: HubTemplate_Briefing
		{
			looped = 1;
		};

		class CutSceneAnimationBaseZoZo;
		class HubBriefing_ext_Contact: CutSceneAnimationBaseZoZo
		{
			delete looped;
		};

		class HubSpectator_stand;
		class HubSpectator_stand_Contact: HubSpectator_stand
		{
			delete looped;
		};
	};
};
