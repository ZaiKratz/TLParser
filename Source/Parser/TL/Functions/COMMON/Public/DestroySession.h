#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class DestroySession : public TLBaseObject
{
public:
	DestroySession();
	DestroySession(unsigned long long session_id);

	~DestroySession();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetSessionId() const
	{
		 return this->session_id;
	}

	TLBaseObject* GetResult() const
	{
		 return this->result;
	}

private:
	unsigned long long session_id;
	TLBaseObject* result;
};
} //end namespace block
