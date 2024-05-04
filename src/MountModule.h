#pragma once

#include "Player.h"

class MountModule {
public:
    static void Initialize();
    static void Shutdown();

private:
    static bool CanMountUnderForm(Player* player, uint32 mountSpellID);
    static void OnMount(Player* player, uint32 mountSpellID);
    static void OnDismount(Player* player);
};
