#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateChatAdmins : public TLBaseObject
{
public:
	UpdateChatAdmins();
	UpdateChatAdmins(int32 chat_id, bool enabled, int32 version);

	~UpdateChatAdmins();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	bool Getenabled() const
	{
		 return this->enabled;
	}

	int32 Getversion() const
	{
		 return this->version;
	}

private:
	int32 chat_id;
	 bool enabled;
	 int32 version;
};
} //end namespace block
