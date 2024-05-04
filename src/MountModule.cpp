#include "MountModule.h"
#include "Config.h"

void MountModule::Initialize() {
    sHookMgr->RegisterHook(SERVER_HOOK_MOUNT, &MountModule::OnMount);
    sHookMgr->RegisterHook(SERVER_HOOK_DISMOUNT, &MountModule::OnDismount);
}

void MountModule::Shutdown() {
    sHookMgr->RemoveHook(SERVER_HOOK_MOUNT, &MountModule::OnMount);
    sHookMgr->RemoveHook(SERVER_HOOK_DISMOUNT, &MountModule::OnDismount);
}

bool MountModule::CanMountUnderForm(Player* player, uint32 mountSpellID) {
    std::vector<uint32> allowedForms = sConfigMgr->GetUInt32VectorDefault("Mounting.AllowedForms", {});

    uint32 shapeshiftForm = player->GetShapeshiftForm();
    for (uint32 formID : allowedForms) {
        if (shapeshiftForm == formID && mountSpellID == formID) {
            return true;
        }
    }
    return false;
}

void MountModule::OnMount(Player* player, uint32 mountSpellID) {
    if (CanMountUnderForm(player, mountSpellID)) {
        player->Mount(mountSpellID);
    } else {
        player->SendErrorMessage("You cannot mount in this form.");
    }
}

void MountModule::OnDismount(Player* player) {
    player->Dismount();
}
