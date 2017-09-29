#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageID : public TLBaseObject
{
public:
	InputBotInlineMessageID();
	InputBotInlineMessageID(int32 dc_id, unsigned long long id, unsigned long long access_hash);

	~InputBotInlineMessageID();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetDcId() const
	{
		 return this->dc_id;
	}

	unsigned long long Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

private:
	int32 dc_id;
	 unsigned long long id;
	 unsigned long long access_hash;
};
} //end namespace block
