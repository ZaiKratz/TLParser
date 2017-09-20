#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InitConnection : public TLBaseObject
{
public:
	InitConnection();
	InitConnection(int32 api_id, FString device_model, FString system_version, FString app_version, FString system_lang_code, FString lang_pack, FString lang_code, TLBaseObject* query);

	~InitConnection();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 api_id;
	 FString device_model;
	 FString system_version;
	 FString app_version;
	 FString system_lang_code;
	 FString lang_pack;
	 FString lang_code;
	 TLBaseObject* query;
	TLBaseObject* result;
};
} //end namespace block
