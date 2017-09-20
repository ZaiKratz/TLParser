#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoneCall.h"
#include "../../../Types/Common/Public/DataJSON.h"

//begin namespace block
namespace PHONE
{
class SaveCallDebug : public TLBaseObject
{
public:
	SaveCallDebug();
	SaveCallDebug(COMMON::InputPhoneCall* peer, COMMON::DataJSON* debug);

	~SaveCallDebug();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputPhoneCall* peer;
	 COMMON::DataJSON* debug;
	bool result;
};
} //end namespace block
