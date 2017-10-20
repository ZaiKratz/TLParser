#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class DestroySessionOk : public TLBaseObject
{
public:
	DestroySessionOk();
	DestroySessionOk(unsigned long long session_id);

	~DestroySessionOk();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetSessionId() const
	{
		 return this->session_id;
	}

private:
	unsigned long long session_id;
};
} //end namespace block
