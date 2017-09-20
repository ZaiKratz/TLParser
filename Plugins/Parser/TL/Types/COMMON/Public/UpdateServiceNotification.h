#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/MessageMedia.h"
#include "../../../Types/Private/MessageEntity.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateServiceNotification : public PRIVATE::Update
{
public:
	UpdateServiceNotification();
	UpdateServiceNotification(bool popup, FDateTime inbox_date, FString type, FString message, PRIVATE::MessageMedia* media, TArray<PRIVATE::MessageEntity*> entities);

	~UpdateServiceNotification();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool popup;
	 FDateTime inbox_date;
	 FString type;
	 FString message;
	 PRIVATE::MessageMedia* media;
	 TArray<PRIVATE::MessageEntity*> entities;
};
} //end namespace block
