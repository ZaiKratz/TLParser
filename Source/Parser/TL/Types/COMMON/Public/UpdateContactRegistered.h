#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateContactRegistered : public PRIVATE::Update
{
public:
	UpdateContactRegistered();
	UpdateContactRegistered(int32 user_id, FDateTime date);

	~UpdateContactRegistered();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

private:
	int32 user_id;
	 FDateTime date;
};
} //end namespace block