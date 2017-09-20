#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputFileLocation.h"

//begin namespace block
namespace COMMON
{
class InputDocumentFileLocation : public TLBaseObject
{
public:
	InputDocumentFileLocation();
	InputDocumentFileLocation(unsigned long long id, unsigned long long access_hash, int32 version);

	~InputDocumentFileLocation();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
	 unsigned long long access_hash;
	 int32 version;
};
} //end namespace block
