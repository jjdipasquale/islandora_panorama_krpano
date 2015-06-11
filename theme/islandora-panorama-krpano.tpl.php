<?php

/**
 * @file
 *
 * Theme for the KRPano Panorama Viewer.
 */

?>

<?php
	$module_path = drupal_get_path('module', 'islandora_panorama_krpano');
	$xmlpath = '/panorama_krpano_xml/' . $object;
?>


<div id="pano" class="islandora-panorama-krpano" style="width:800px;height:600px;">
   <script type="text/javascript" src="/<?php echo $module_path; ?>/js/krpano.js"></script>
	<noscript>
	<div style="text-align:center;">ERROR:<br/><br/>Javascript not activated
	</div>
	</noscript>
	<script>
		embedpano({swf:"3954528285_bdf96c9953_o.swf", xml:"<?php echo $xmlpath; ?>", target:"pano", html5:"prefer", passQueryParameters:true});
	</script>
</div>
