#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ImportedContact : public TLBaseObject
{
public:
	ImportedContact();
	ImportedContact(int32 user_id, unsigned long long client_id);

	~ImportedContact();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 unsigned long long client_id;
};
} //end namespace block
