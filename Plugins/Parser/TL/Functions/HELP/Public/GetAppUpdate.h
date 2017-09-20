#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Help/Public/AppUpdate.h"

//begin namespace block
namespace HELP
{
class GetAppUpdate : public TLBaseObject
{
public:
	GetAppUpdate();
	~GetAppUpdate();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	HELP::AppUpdate* result;
};
} //end namespace block
