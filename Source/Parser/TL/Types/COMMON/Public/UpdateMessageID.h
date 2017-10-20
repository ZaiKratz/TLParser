#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateMessageID : public TLBaseObject
{
public:
	UpdateMessageID();
	UpdateMessageID(int32 id, unsigned long long random_id);

	~UpdateMessageID();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getid() const
	{
		 return this->id;
	}

	unsigned long long GetRandomId() const
	{
		 return this->random_id;
	}

private:
	int32 id;
	 unsigned long long random_id;
};
} //end namespace block
