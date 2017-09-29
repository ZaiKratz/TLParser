#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateEncryptedMessagesRead : public PRIVATE::Update
{
public:
	UpdateEncryptedMessagesRead();
	UpdateEncryptedMessagesRead(int32 chat_id, FDateTime max_date, FDateTime date);

	~UpdateEncryptedMessagesRead();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	FDateTime GetMaxDate() const
	{
		 return this->max_date;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

private:
	int32 chat_id;
	 FDateTime max_date;
	 FDateTime date;
};
} //end namespace block
