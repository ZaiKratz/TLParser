#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace AUTH
{
class Authorization : public TLBaseObject
{
public:
	Authorization();
	Authorization(int32 tmp_sessions, COMMON::User* user);

	~Authorization();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetTmpSessions() const
	{
		 return this->tmp_sessions;
	}

	COMMON::User*  Getuser() const
	{
		 return this->user;
	}

private:
	int32 tmp_sessions;
	 COMMON::User* user;
};
} //end namespace block
