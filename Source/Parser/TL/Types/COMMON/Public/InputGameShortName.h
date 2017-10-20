#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"

//begin namespace block
namespace COMMON
{
class InputGameShortName : public TLBaseObject
{
public:
	InputGameShortName();
	InputGameShortName(COMMON::InputUser* bot_id, FString short_name);

	~InputGameShortName();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputUser*  GetBotId() const
	{
		 return this->bot_id;
	}

	FString GetShortName() const
	{
		 return this->short_name;
	}

private:
	COMMON::InputUser* bot_id;
	 FString short_name;
};
} //end namespace block
