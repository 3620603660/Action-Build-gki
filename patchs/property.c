diff --git a/drivers/of/property.c b/drivers/of/property.c
--- a/drivers/of/property.c
+++ b/drivers/of/property.c
@@ -451,3 +451,6 @@
int of_property_read_string(const struct device_node *np, const char *propname,
const char **out_string)
{
const struct property *prop = of_find_property(np, propname, NULL);
if (!prop)
return -EINVAL;
if (!prop->length)
return -ENODATA;
if (strnlen(prop->value, prop->length) >= prop->length)
return -EILSEQ; 
*out_string = prop->value;
+ if (strcmp(propname, "type") == 0 && strcmp(prop->value, "HMBIRD_OGKI") == 0) {
+ *out_string = "HMBIRD_GKI";
+ }
return 0;
}
EXPORT_SYMBOL_GPL(of_property_read_string);
