#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputUser : public TLBaseObject
{
public:
	InputUser();
	InputUser(int32 user_id, unsigned long long access_hash);

	~InputUser();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 unsigned long long access_hash;
};
} //end namespace block
