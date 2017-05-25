/*
 * This is automatically generated callbacks file
 * It contains 3 parts: Configuration callbacks, RPC callbacks and state data callbacks.
 * Do NOT alter function signatures or any structures unless you know exactly what you are doing.
 */

#include <stdlib.h>
#include <sys/inotify.h>
#include <libxml/tree.h>
#include <libxml/xpathInternals.h>
#include <libnetconf_xml.h>

#define SF_INFO_XML_PATH "/home/mnc-boo/boo_netopeer/sf-desc-mon-rpt/"

/* transAPI version which must be compatible with libnetconf */
int transapi_version = 6;

/* Signal to libnetconf that configuration data were modified by any callback.
 * 0 - data not modified
 * 1 - data have been modified
 */
int config_modified = 0;

/*
 * Determines the callbacks order.
 * Set this variable before compilation and DO NOT modify it in runtime.
 * TRANSAPI_CLBCKS_LEAF_TO_ROOT (default)
 * TRANSAPI_CLBCKS_ROOT_TO_LEAF
 */
const TRANSAPI_CLBCKS_ORDER_TYPE callbacks_order = TRANSAPI_CLBCKS_ORDER_DEFAULT;

/* Do not modify or set! This variable is set by libnetconf to announce edit-config's error-option
Feel free to use it to distinguish module behavior for different error-option values.
 * Possible values:
 * NC_EDIT_ERROPT_STOP - Following callback after failure are not executed, all successful callbacks executed till
                         failure point must be applied to the device.
 * NC_EDIT_ERROPT_CONT - Failed callbacks are skipped, but all callbacks needed to apply configuration changes are executed
 * NC_EDIT_ERROPT_ROLLBACK - After failure, following callbacks are not executed, but previous successful callbacks are
                         executed again with previous configuration data to roll it back.
 */
NC_EDIT_ERROPT_TYPE erropt = NC_EDIT_ERROPT_NOTSET;

/**
 * @brief Initialize plugin after loaded and before any other functions are called.

 * This function should not apply any configuration data to the controlled device. If no
 * running is returned (it stays *NULL), complete startup configuration is consequently
 * applied via module callbacks. When a running configuration is returned, libnetconf
 * then applies (via module's callbacks) only the startup configuration data that
 * differ from the returned running configuration data.

 * Please note, that copying startup data to the running is performed only after the
 * libnetconf's system-wide close - see nc_close() function documentation for more
 * information.

 * @param[out] running	Current configuration of managed device.

 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int transapi_init(xmlDocPtr *running) {
	return EXIT_SUCCESS;
}

/**
 * @brief Free all resources allocated on plugin runtime and prepare plugin for removal.
 */
void transapi_close(void) {
	return;
}

/**
 * @brief Retrieve state data from device and return them as XML document
 *
 * @param model	Device data model. libxml2 xmlDocPtr.
 * @param running	Running datastore content. libxml2 xmlDocPtr.
 * @param[out] err  Double pointer to error structure. Fill error when some occurs.
 * @return State data as libxml2 xmlDocPtr or NULL in case of error.
 */
xmlDocPtr get_state_data(xmlDocPtr model, xmlDocPtr running, struct nc_err **err) {
	return(NULL);
}
/*
 * Mapping prefixes with namespaces.
 * Do NOT modify this structure!
 */
struct ns_pair namespace_mapping[] = {{"sf-desc-mon-rpt", "urn.intel.params:xml:ns:sf-desc-mon-rpt"}, {NULL, NULL}};

/*
 * CONFIGURATION callbacks
 * Here follows set of callback functions run every time some change in associated part of running datastore occurs.
 * You can safely modify the bodies of all function as well as add new functions for better lucidity of code.
 */

/**
 * @brief This callback will be run when node in path /sf-desc-mon-rpt:service-function-description-monitoring-report changes
 *
 * @param[in] data	Double pointer to void. Its passed to every callback. You can share data using it.
 * @param[in] op	Observed change in path. XMLDIFF_OP type.
 * @param[in] old_node	Old configuration node. If op == XMLDIFF_ADD, it is NULL.
 * @param[in] new_node	New configuration node. if op == XMLDIFF_REM, it is NULL.
 * @param[out] error	If callback fails, it can return libnetconf error structure with a failure description.
 *
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
/* !DO NOT ALTER FUNCTION SIGNATURE! */
int callback_sf_desc_mon_rpt_service_function_description_monitoring_report(void **data, XMLDIFF_OP op, xmlNodePtr old_node, xmlNodePtr new_node, struct nc_err **error) {
	return EXIT_SUCCESS;
}

/*
 * Structure transapi_config_callbacks provide mapping between callback and path in configuration datastore.
 * It is used by libnetconf library to decide which callbacks will be run.
 * DO NOT alter this structure
 */
struct transapi_data_callbacks clbks =  {
	.callbacks_count = 1,
	.data = NULL,
	.callbacks = {
		{.path = "/sf-desc-mon-rpt:service-function-description-monitoring-report", .func = callback_sf_desc_mon_rpt_service_function_description_monitoring_report}
	}
};

/**
 * @brief Get a node from the RPC input. The first found node is returned, so if traversing lists,
 * call repeatedly with result->next as the node argument.
 *
 * @param name	Name of the node to be retrieved.
 * @param node	List of nodes that will be searched.
 * @return Pointer to the matching node or NULL
 */
xmlNodePtr get_rpc_node(const char *name, const xmlNodePtr node) {
	xmlNodePtr ret = NULL;

	for (ret = node; ret != NULL; ret = ret->next) {
		if (xmlStrEqual(BAD_CAST name, ret->name)) {
			break;
		}
	}

	return ret;
}

/*
 * RPC callbacks
 * Here follows set of callback functions run every time RPC specific for this device arrives.
 * You can safely modify the bodies of all function as well as add new functions for better lucidity of code.
 * Every function takes an libxml2 list of inputs as an argument.
 * If input was not set in RPC message argument is set to NULL. To retrieve each argument, preferably use get_rpc_node().
 */

nc_reply *rpc_get_SF_description(xmlNodePtr input){
            nc_reply *reply, *boo_reply;
            xmlDocPtr state;
            xmlNodePtr root;
            xmlNsPtr ns;

            xmlDocPtr read_doc;
            xmlNodePtr read_doc_cur;
            xmlNodePtr port;
            xmlNodeSetPtr nodeset; 
            xmlXPathContextPtr data_ctxt;
            xmlXPathObjectPtr query_result;
            xmlChar *data_plane_ip, *data_plane_port, *type, *num_of_port, *supported_packet_rate, *supported_bandwidth,  *supported_ACL_number, *RIB_size, *FIB_size, *port_id, *ipaddress, *macaddress, *port_supported_bandwidth;

            int i;
            state = xmlNewDoc(BAD_CAST "1.0");
            root = xmlNewDocNode(state, NULL, BAD_CAST "description-info", NULL);
            xmlDocSetRootElement(state, root);
            ns = xmlNewNs(root, BAD_CAST "urn.intel.params:xml:ns:sf-desc-mon-rpt", NULL);
            xmlSetNs(root, ns);

            read_doc = xmlParseFile(SF_INFO_XML_PATH"service-function-description-monitor-report.xml");

            if(read_doc == NULL)
            {
                fprintf(stderr,"Document service-function-description-monitor-report.xml not parsed successfully.\n");
                xmlFreeDoc(read_doc);
                xmlFreeNode(read_doc_cur);
                return;
            }

            read_doc_cur = xmlDocGetRootElement(read_doc);

            if(read_doc_cur == NULL){
                fprintf(stderr,"Empty document.\n");
                xmlFreeDoc(read_doc);
                xmlFreeNode(read_doc_cur);
                return;
            }

            if(xmlStrcmp(read_doc_cur->name,(const xmlChar *)"service-function-description-monitor-report")) {
                fprintf(stderr,"document of the wrong type, root node != service-function-description-monitor-report.\n");
                xmlFreeDoc(read_doc);
                xmlFreeNode(read_doc_cur);
                return;
            }

            // create xpath evaluation context 
            if ((data_ctxt = xmlXPathNewContext(read_doc)) == NULL) {
                fprintf(stderr,"%s: service-function-description-monitor-report configuration data XPath context can not be created.", __func__);
            }

           // xmlNodePtr sf_description = xmlNewNode(NULL, BAD_CAST "SF-description");
            xmlNodePtr capabilities = xmlNewNode(NULL, BAD_CAST "capabilities");
            xmlNodePtr ports_bandwidth = xmlNewNode(NULL, BAD_CAST "ports-bandwidth");
           // xmlAddChild(root, sf_description);
            xmlAddChild(root, capabilities);
            xmlAddChild(capabilities, ports_bandwidth);

            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//data-plane-ip", data_ctxt))!=NULL) {
                data_plane_ip = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(root, NULL, BAD_CAST "data-plane-ip", data_plane_ip);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//data-plane-port", data_ctxt))!=NULL) {
                data_plane_port = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(root, NULL, BAD_CAST "data-plane-port", data_plane_port);
            }
           if ((query_result = xmlXPathEvalExpression(BAD_CAST "//type", data_ctxt))!=NULL) {
                type = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(root, NULL, BAD_CAST "type", type);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//number-of-dataports", data_ctxt))!=NULL) {
                num_of_port = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(root, NULL, BAD_CAST "number-of-dataports", num_of_port);
            }

            // capability

            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//capabilities/supported-packet-rate", data_ctxt))!=NULL) {
                supported_packet_rate = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(capabilities, NULL, BAD_CAST "supported-packet-rate", supported_packet_rate);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//capabilities/supported-bandwidth", data_ctxt))!=NULL) {
                supported_bandwidth = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(capabilities, NULL, BAD_CAST "supported-bandwidth", supported_bandwidth);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//capabilities/supported-ACL-number", data_ctxt))!=NULL) {
                supported_ACL_number = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(capabilities, NULL, BAD_CAST "supported-ACL-number", supported_ACL_number);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//capabilities/FIB-size", data_ctxt))!=NULL) {
                FIB_size = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(capabilities, NULL, BAD_CAST "FIB-size", FIB_size);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//capabilities/RIB-size", data_ctxt))!=NULL) {
                RIB_size = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(capabilities, NULL, BAD_CAST "RIB-size", RIB_size);	
            }

            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//capabilities/ports-bandwidth/port-bandwidth", data_ctxt))!=NULL) {
                nodeset = query_result->nodesetval;
                for (i=0; i < nodeset->nodeNr; i++) {
                    xmlNodePtr port_bandwidth = xmlNewNode(NULL, BAD_CAST "port-bandwidth");
                    xmlAddChild(ports_bandwidth, port_bandwidth);
                    for(port = nodeset->nodeTab[i]->xmlChildrenNode;port != NULL;port = port->next) {
                        if((!xmlStrcmp(port->name,(const xmlChar *)"port-id"))) {
                            port_id = xmlNodeListGetString(read_doc, port->xmlChildrenNode, 1);
                            xmlNewChild(port_bandwidth, NULL, BAD_CAST "port-id", port_id);
                        } else if((!xmlStrcmp(port->name, (const xmlChar *)"ipaddress"))) {
                            ipaddress = xmlNodeListGetString(read_doc, port->xmlChildrenNode, 1);
                            xmlNewChild(port_bandwidth, NULL, BAD_CAST "ipaddress", ipaddress);
                        } else if((!xmlStrcmp(port->name, (const xmlChar *)"macaddress"))) {
                            macaddress = xmlNodeListGetString(read_doc, port->xmlChildrenNode, 1);
                            xmlNewChild(port_bandwidth, NULL, BAD_CAST "macaddress", macaddress);
                        } else if((!xmlStrcmp(port->name, (const xmlChar *)"supported-bandwidth"))) {
                            port_supported_bandwidth = xmlNodeListGetString(read_doc, port->xmlChildrenNode, 1);
                            xmlNewChild(port_bandwidth, NULL, BAD_CAST "supported-bandwidth", port_supported_bandwidth);
                        }
                    }
                }
            }

            xmlFree(data_plane_ip);
            xmlFree(data_plane_port);
            xmlFree(num_of_port);
            xmlFree(type);
            xmlFree(supported_packet_rate);
            xmlFree(supported_bandwidth); 
            xmlFree(supported_ACL_number);
            xmlFree(RIB_size);
            xmlFree(FIB_size);
            xmlFree(port_id);
            xmlFree(ipaddress);
            xmlFree(macaddress);
            xmlFree(port_supported_bandwidth);

//           reply = (nc_reply *)(intptr_t)nc_msg_create(root, "rpc-reply");
//           reply = (nc_reply *)(intptr_t)ncxml_reply_build(read_doc);
 //          reply = (nc_reply *)(intptr_t)ncxml_reply_data_ns(root, "urn.intel.params:xml:ns:sf-desc-mon-rpt/");
             reply = (nc_reply *)(intptr_t)ncxml_reply_data_boo(root);

            
            xmlFreeNode(root);
            xmlFreeNode(port);
            xmlFreeNode(read_doc_cur);
            return reply;
        }

nc_reply *rpc_get_SF_monitoring_info(xmlNodePtr input){
            nc_reply *reply;
            xmlDocPtr state;
            xmlNodePtr root;
            xmlNsPtr ns;
            
            xmlDocPtr read_doc;
            xmlNodePtr read_doc_cur;
            xmlNodePtr port;
	        xmlNodeSetPtr nodeset; 
            xmlXPathContextPtr data_ctxt;
            xmlXPathObjectPtr query_result;
            xmlChar *liveness, *packet_rate_utilization, *bandwidth_utilization, *CPU_utilization, *memory_utilization, *available_memory, *RIB_utilization, *FIB_utilization, *power_utilization, *port_id, *port_bandwidth_utilization;

            int i;
            state = xmlNewDoc(BAD_CAST "1.0");
            root = xmlNewDocNode(state, NULL, BAD_CAST "monitoring-info", NULL);
            xmlDocSetRootElement(state, root);
            ns = xmlNewNs(root, BAD_CAST "urn.intel.params:xml:ns:sf-desc-mon-rpt", NULL);
            xmlSetNs(root, ns);

            read_doc = xmlParseFile(SF_INFO_XML_PATH"service-function-description-monitor-report.xml");

            if(read_doc == NULL)
            {
                fprintf(stderr,"Document service-function-description-monitor-report.xml not parsed successfully.\n");
                xmlFreeDoc(read_doc);
                xmlFreeNode(read_doc_cur);
                return;
            }

            read_doc_cur = xmlDocGetRootElement(read_doc);

            if(read_doc_cur == NULL){
                fprintf(stderr,"Empty document.\n");
                xmlFreeDoc(read_doc);
                xmlFreeNode(read_doc_cur);
                return;
            }

            if(xmlStrcmp(read_doc_cur->name,(const xmlChar *)"service-function-description-monitor-report")) {
                fprintf(stderr,"document of the wrong type, root node != service-function-description-monitor-report.\n");
                xmlFreeDoc(read_doc);
                xmlFreeNode(read_doc_cur);
                return;
            }

            // create xpath evaluation context 
            if ((data_ctxt = xmlXPathNewContext(read_doc)) == NULL) {
                fprintf(stderr,"%s: service-function-description-monitor-report configuration data XPath context can not be created.", __func__);
            }

  //          xmlNodePtr sf_monitoring_info = xmlNewNode(NULL, BAD_CAST "SF-monitoring-info");
            xmlNodePtr utilization = xmlNewNode(NULL, BAD_CAST "resource-utilization");
            xmlNodePtr ports_bandwidth_util = xmlNewNode(NULL, BAD_CAST "SF-ports-bandwidth-utilization");
  //          xmlAddChild(root, sf_monitoring_info);
            xmlAddChild(root, utilization);
            xmlAddChild(utilization, ports_bandwidth_util);

            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//liveness", data_ctxt))!=NULL) {
                liveness = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(root, NULL, BAD_CAST "liveness", liveness);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//resource-utilization/packet-rate-utilization", data_ctxt))!=NULL) {
                packet_rate_utilization = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(utilization, NULL, BAD_CAST "packet-rate-utilization", packet_rate_utilization);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//resource-utilization/bandwidth-utilization", data_ctxt))!=NULL) {
                bandwidth_utilization = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(utilization, NULL, BAD_CAST "bandwidth-utilization", bandwidth_utilization);	
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//resource-utilization/CPU-utilization", data_ctxt))!=NULL) {
                CPU_utilization = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(utilization, NULL, BAD_CAST "CPU-utilization", CPU_utilization);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//resource-utilization/memory-utilization", data_ctxt))!=NULL) {
                memory_utilization = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(utilization, NULL, BAD_CAST "memory-utilization", memory_utilization);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//resource-utilization/available-memory", data_ctxt))!=NULL) {
                available_memory = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(utilization, NULL, BAD_CAST "available-memory", available_memory);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//resource-utilization/RIB-utilization", data_ctxt))!=NULL) {
                RIB_utilization = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(utilization, NULL, BAD_CAST "RIB-utilization", RIB_utilization);
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//resource-utilization/FIB-utilization", data_ctxt))!=NULL) {
                FIB_utilization = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(utilization, NULL, BAD_CAST "FIB-utilization", FIB_utilization);	
            }
            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//resource-utilization/power-utilization", data_ctxt))!=NULL) {
                power_utilization = xmlNodeListGetString(read_doc, query_result->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
                xmlNewChild(utilization, NULL, BAD_CAST "power-utilization", power_utilization);	
            }

            if ((query_result = xmlXPathEvalExpression(BAD_CAST "//resource-utilization/SF-ports-bandwidth-utilization/port-bandwidth-utilization", data_ctxt))!=NULL) {
                nodeset = query_result->nodesetval;
                for (i=0; i < nodeset->nodeNr; i++) {
                    xmlNodePtr port_bandwidth_util = xmlNewNode(NULL, BAD_CAST "port-bandwidth-utilization");
                    xmlAddChild(ports_bandwidth_util, port_bandwidth_util);
                    for(port = nodeset->nodeTab[i]->xmlChildrenNode;port != NULL;port = port->next) {
                        if((!xmlStrcmp(port->name,(const xmlChar *)"port-id"))) {
                            port_id = xmlNodeListGetString(read_doc, port->xmlChildrenNode, 1);
                            xmlNewChild(port_bandwidth_util, NULL, BAD_CAST "port-id", port_id);
                        } else if((!xmlStrcmp(port->name, (const xmlChar *)"bandwidth-utilization"))) {
                            port_bandwidth_utilization = xmlNodeListGetString(read_doc, port->xmlChildrenNode, 1);
                            xmlNewChild(port_bandwidth_util, NULL, BAD_CAST "bandwidth-utilization", port_bandwidth_utilization);
                        }
                    }
                }
            }

            xmlFree(liveness);
            xmlFree(packet_rate_utilization);
            xmlFree(bandwidth_utilization);
            xmlFree(CPU_utilization);
            xmlFree(memory_utilization); 
            xmlFree(available_memory);
            xmlFree(RIB_utilization);
            xmlFree(FIB_utilization);
            xmlFree(power_utilization);
            xmlFree(port_id);
            xmlFree(port_bandwidth_utilization);

//             reply = (nc_reply *)(intptr_t)nc_msg_create(root, "rpc-reply");
//              reply = (nc_reply *)(intptr_t)ncxml_msg_build(root);
            reply = (nc_reply *)(intptr_t)ncxml_reply_data_boo(root);
//            reply = (nc_reply *)(intptr_t)ncxml_reply_data_ns(root, "urn.intel.params:xml:ns:sf-desc-mon-rpt");
            xmlFreeNode(root);
            xmlFreeNode(port);
            xmlFreeNode(read_doc_cur);
            return reply; 
        }
/*
 * Structure transapi_rpc_callbacks provides mapping between callbacks and RPC messages.
 * It is used by libnetconf library to decide which callbacks will be run when RPC arrives.
 * DO NOT alter this structure
 */
struct transapi_rpc_callbacks rpc_clbks = {
	.callbacks_count = 2,
	.callbacks = {
		{.name="get-SF-description", .func=rpc_get_SF_description},
		{.name="get-SF-monitoring-info", .func=rpc_get_SF_monitoring_info}
	}
};

/*
 * Structure transapi_file_callbacks provides mapping between specific files
 * (e.g. configuration file in /etc/) and the callback function executed when
 * the file is modified.
 * The structure is empty by default. Add items, as in example, as you need.
 *
 * Example:
 * int example_callback(const char *filepath, xmlDocPtr *edit_config, int *exec) {
 *     // do the job with changed file content
 *     // if needed, set edit_config parameter to the edit-config data to be applied
 *     // if needed, set exec to 1 to perform consequent transapi callbacks
 *     return 0;
 * }
 *
 * struct transapi_file_callbacks file_clbks = {
 *     .callbacks_count = 1,
 *     .callbacks = {
 *         {.path = "/etc/my_cfg_file", .func = example_callback}
 *     }
 * }
 */
struct transapi_file_callbacks file_clbks = {
	.callbacks_count = 0,
	.callbacks = {{NULL}}
};

