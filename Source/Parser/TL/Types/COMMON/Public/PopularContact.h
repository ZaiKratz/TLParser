#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PopularContact : public TLBaseObject
{
public:
	PopularContact();
	PopularContact(unsigned long long client_id, int32 importers);

	~PopularContact();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetClientId() const
	{
		 return this->client_id;
	}

	int32 Getimporters() const
	{
		 return this->importers;
	}

private:
	unsigned long long client_id;
	 int32 importers;
};
} //end namespace block
