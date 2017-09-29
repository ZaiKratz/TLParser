#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class DhConfig : public TLBaseObject
{
public:
	DhConfig();
	DhConfig(int32 g, TArray<uint8> p, int32 version, TArray<uint8> random);

	~DhConfig();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getg() const
	{
		 return this->g;
	}

	TArray<uint8>  Getp() const
	{
		 return this->p;
	}

	int32 Getversion() const
	{
		 return this->version;
	}

	TArray<uint8>  Getrandom() const
	{
		 return this->random;
	}

private:
	int32 g;
	 TArray<uint8> p;
	 int32 version;
	 TArray<uint8> random;
};
} //end namespace block
