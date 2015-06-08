
class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class GVAR(open) {
                    displayName = CSTRING(activateMonitor);
                    condition = QUOTE([ARR_2(ACE_player,'ACE_HuntIR_monitor')] call EFUNC(common,hasItem));
                    statement = QUOTE(call FUNC(huntir));
                    showDisabled = 0;
                    priority = 2;
                    icon = PATHTOF(UI\w_huntir_monitor_ca.paa);
                    exceptions[] = {};
                };
            };
        };
    };
    
    class Parachute_02_base_F;
    class ACE_HuntIR: Parachute_02_base_F {
        scope = 1;
        displayName = "HuntIR";
        model = PATHTOF(data\huntir.p3d);
        castDriverShadow = 0;
        soundEnviron[] = {"z\ace\addons\apl\sounds\padak_let", 0.316228, 1, 80};
        soundCrash[] = {"", db-30, 1 };
        soundLandCrash[] = {"", db-30, 1 };
        soundWaterCrash[] = {"", db10, 1 };
        mapSize = 0;
    };

    class Item_Base_F;
    class ACE_Item_HuntIR_monitor: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(monitor_displayName);
        vehicleClass = "Items";
        class TransportItems {
            class ACE_HuntIR_monitor {
                name = "ACE_HuntIR_monitor";
                count = 1;
            };
        };
    };
    
    class ReammoBox_F;
    class ACE_HuntIR_Box: ReammoBox_F {
        model = PATHTOF(data\ace_huntirbox.p3d);
        displayName = $STR_DN_ACE_HUNTIRBOX;
        class TransportItems {
            MACRO_ADDITEM(ACE_HuntIR_monitor,5);
        };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(ACE_HuntIR_M203,20);
        };
    };
};
