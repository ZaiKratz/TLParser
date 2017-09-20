#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace CONTEST
{
class SaveDeveloperInfo : public TLBaseObject
{
public:
	SaveDeveloperInfo();
	SaveDeveloperInfo(int32 vk_id, FString name, FString phone_number, int32 age, FString city);

	~SaveDeveloperInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 vk_id;
	 FString name;
	 FString phone_number;
	 int32 age;
	 FString city;
	bool result;
};
} //end namespace block
