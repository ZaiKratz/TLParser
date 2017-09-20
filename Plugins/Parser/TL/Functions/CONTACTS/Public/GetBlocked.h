#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Contacts/Public/Blocked.h"

//begin namespace block
namespace CONTACTS
{
class GetBlocked : public TLBaseObject
{
public:
	GetBlocked();
	GetBlocked(int32 offset, int32 limit);

	~GetBlocked();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 offset;
	 int32 limit;
	CONTACTS::Blocked* result;
};
} //end namespace block
