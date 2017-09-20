#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateUserName : public PRIVATE::Update
{
public:
	UpdateUserName();
	UpdateUserName(int32 user_id, FString first_name, FString last_name, FString username);

	~UpdateUserName();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 FString first_name;
	 FString last_name;
	 FString username;
};
} //end namespace block
