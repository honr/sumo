#include <string>
#include <utils/sumoxml/SUMOSAXHandler.h>
#include <utils/common/UtilExceptions.h>
#include <netbuild/NBNode.h>
#include <netbuild/NBNodeCont.h>
#include <utils/sumoxml/SUMOXMLDefinitions.h>
#include "NBSUMOHandlerNodes.h"

using namespace std;

NBSUMOHandlerNodes::NBSUMOHandlerNodes(LoadFilter what, bool warn, bool verbose)
    : SUMOSAXHandler(warn, verbose),
    _loading(what)
{
}


NBSUMOHandlerNodes::~NBSUMOHandlerNodes()
{
}


void
NBSUMOHandlerNodes::myStartElement(int element, const std::string &name,
                                   const Attributes &attrs)
{
    switch(element) {
    case SUMO_TAG_JUNCTION:
        if(_loading==LOADFILTER_ALL) {
            addNode(attrs);
        }
        break;
    default:
        break;
    }
}


void
NBSUMOHandlerNodes::addNode(const Attributes &attrs)
{
    string id;
    try {
        // retrieve the id of the node
        id = getString(attrs, SUMO_ATTR_ID);
/*        string name = id;
        // retrieve the name of the node
        try {
            name = getString(attrs, SUMO_ATTR_NAME);
        } catch (EmptyData) {
        }*/
        string typestr;
        // get the type of the node
        try {
            typestr = getString(attrs, SUMO_ATTR_TYPE);
        } catch (EmptyData) {
            addError("sumo-file",
                string("The type of the junction '") + id +
                string("' is not given."));
            return;
        }
        // check whether the type string is valid by converting it to the known
        //  junction types
        int type = -1;
        if(typestr=="none") {
            type = NBNode::TYPE_NOJUNCTION;
        } else if(typestr=="traffic_light") {
            type = NBNode::TYPE_TRAFFIC_LIGHT;
        } else if(typestr=="priority") {
            type = NBNode::TYPE_PRIORITY_JUNCTION;
        } else if(typestr=="right_before_left") {
            type = NBNode::TYPE_RIGHT_BEFORE_LEFT;
        } else if(typestr=="DEAD_END") {
            type = NBNode::TYPE_DEAD_END;
        }
        if(type<0) {
            addError("sumo-file",
                string("The type '") + typestr + string("' of junction '") +
                id + string("is not known."));
            return;
        }
        // get the position of the node
        double x, y;
        x = getFloatSecure(attrs, SUMO_ATTR_X, -1);
        y = getFloatSecure(attrs, SUMO_ATTR_Y, -1);
        if(x<0||y<0) {
            if(x<0) {
                addError("sumo-file",
                    string("The x-position of the junction '") +
                    id + string("' is not valid."));
            }
            if(y<0) {
                addError("sumo-file",
                    string("The y-position of the junction '") +
                    id + string("' is not valid."));
            }
            return;
        }
        // get the key
        string key;
        try {
            key = getString(attrs, SUMO_ATTR_KEY);
        } catch (EmptyData) {
            addError("sumo-file",
                string("The key is missing for junction '") + id
                + string("'."));
        }
        // build the node
        NBNodeCont::insert(new NBNode(id, x, y, type, key));
    } catch (EmptyData) {
        addError("sumo-file", "A junction without an id occured.");
    }
}


void
NBSUMOHandlerNodes::myCharacters(int element, const std::string &name,
                                 const std::string &chars)
{
    myCharactersDump(element, name, chars);
}

void
NBSUMOHandlerNodes::myEndElement(int element, const std::string &name)
{
    myEndElementDump(element, name);
}


