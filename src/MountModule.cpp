#include "MountModule.h"
#include "Config.h"
#include "Util.h" 
#include <vector>

class MountModule {
private:
    HookList<std::function<void(Player*, uint32)>> mountHooks;
    HookList<std::function<void(Player*)>> dismountHooks;

public:
    void Initialize() {
        mountHooks += [&](Player* player, uint32 mountSpellID) { OnMount(player, mountSpellID); };
        dismountHooks += [&](Player* player) { OnDismount(player); };
    }

    void Shutdown() {
        mountHooks -= [&](Player* player, uint32 mountSpellID) { OnMount(player, mountSpellID); };
        dismountHooks -= [&](Player* player) { OnDismount(player); };
    }

    bool CanMountUnderForm(Player* player, uint32 mountSpellID) {
        std::vector<uint32> allowedForms = sConfigMgr->GetOption<std::vector<uint32>>("Mounting.AllowedForms", {});

        uint32 shapeshiftForm = player->GetShapeshiftForm();
        return std::find(allowedForms.begin(), allowedForms.end(), shapeshiftForm) != allowedForms.end() && shapeshiftForm == mountSpellID;
    }

    void OnMount(Player* player, uint32 mountSpellID) {
        if (CanMountUnderForm(player, mountSpellID)) {
            player->Mount(mountSpellID);
        }
        else {
            player->SendSystemMessage("You cannot mount in this form.");
        }
    }

    void OnDismount(Player* player) {
        player->Dismount();
    }
};
