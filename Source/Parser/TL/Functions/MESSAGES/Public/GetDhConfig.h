#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/DhConfig.h"

//begin namespace block
namespace MESSAGES
{
class GetDhConfig : public TLBaseObject
{
public:
	GetDhConfig();
	GetDhConfig(int32 version, int32 random_length);

	~GetDhConfig();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getversion() const
	{
		 return this->version;
	}

	int32 GetRandomLength() const
	{
		 return this->random_length;
	}

	MESSAGES::DhConfig* GetResult() const
	{
		 return this->result;
	}

private:
	int32 version;
	 int32 random_length;
	MESSAGES::DhConfig* result;
};
} //end namespace block
